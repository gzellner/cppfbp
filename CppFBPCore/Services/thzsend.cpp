#include <stdio.h>
#include <string.h>
#include "cppfbp.h"
#define INPUT 0
#define OUTPUT 1


int thzrecv(Process *proc, void **ptr, port_ent *peptr, int elem_no,
	    long *size, std::string &type);
int thzdrop(Process *proc, void **ptr);
int thzsend(Process *proc, void **ptr, port_ent *peptr, int elem_no);

int thzsendc(Process *proc, void **ptr, std::string &port)
{
  int elem_no = 0;
  std::string port_name;
  size_t p = port.find_first_of('[');
  size_t q;
  port_ent pe;
		    
  if (p == std::string::npos) 
    port_name = port;
  else {
    q = port.find_first_of(']', p);
    size_t n = q - p - 1;
    elem_no = std::stoi(port.substr(p+1, n));
    port_name = port.substr(p+1);
  }

  //port_ent* pe = (port_ent *) malloc(sizeof(port_ent));   

  pe.port_name = port_name;
  Port * cpp = proc -> out_ports;
  while (cpp != nullptr)
    {
		
      if (cpp -> port_name == port_name){
	break;
      }
		 
      cpp = cpp -> succ;
    }
  pe.cpptr = cpp;
  pe.elem_count = cpp -> elem_count;  
  pe.ret_code = 0;
	
  int value = thzsend(proc, ptr, &pe, elem_no);

  //free (pe);
  return value;
}

int thzsend(Process *proc, void **ptr, port_ent *peptr, int elem_no)
{
  /*  This service takes the data part of an IP - if info is needed from the header,
      you have to back up over the length of the header */

  Process *sptr;
  IPh   *IPptr;
  IPh   *prevIP;
  //IPh   *optr;
  //IPh   *qptr;
  IP   *tptr;
  long size;
  std::string type;
  Port *cpp;
  Cnxt *cnp;
  int value = 0;

  if (peptr -> ret_code == 2) {             
    MSG1(proc->trace,"%s Sending to unconnected port\n", proc -> procname.c_str());
    return(2);
  }

  cpp = (Port *)peptr -> cpptr;
  MSG3(proc->trace,"%s Send start %s[%d]\n", proc -> procname.c_str(),
			  cpp -> port_name.c_str(), elem_no);
	
  cnp = (Cnxt *) cpp -> elem_list[elem_no].gen.connxn;
  if (cnp == nullptr) return(2);

  boost::unique_lock<boost::mutex> lock (cnp -> mtx);  
	
  //cnp ->lock.lock();
	

  if (cnp -> closed) {
    value = 2;
    goto retn;	
  }

  IPptr = (IPh   *) *ptr - 1;       /* back up size of header */
  tptr = (IP *)IPptr;
  if (tptr -> datapart[IPptr -> IP_size] != guard_value)
    printf("Guard byte corrupted: '%s'\n", proc->procname.c_str());
  if (IPptr -> on_stack)
    printf("IP on stack: '%s'\n", proc->procname.c_str());

  if (cpp -> direction != OUTPUT) {
    printf("%s %s SEND Wrong direction\n",
	 proc -> procname.c_str(), peptr -> port_name.c_str());
    value = 3;
    goto retn;
  }
  if (elem_no < 0 || elem_no >= cpp ->elem_count) {
    printf("%s %s SEND Element Number negative or too high\n",
	 proc -> procname.c_str(), peptr -> port_name.c_str());
    value = 3;
    goto retn;
  }
  if (cnp == nullptr) {
    value = 2;
    goto retn;	
  }

  if (cpp -> elem_list[elem_no].closed) {
    value = 1;
    goto retn;	
  }

  if (cnp -> nonterm_upstream_proc_count == 0) {
    value = 1;
    goto retn;
  }

  for (;;) {
		
    if (cnp -> IPcount < cnp -> max_IPcount) break;
		
    proc -> status = SUSPENDED_ON_SEND;
    proc -> waiting_cnxt = cnp;
    MSG1(proc->trace, "%s Send susp\n", proc -> procname.c_str());		

    cnp-> buffer_not_full.wait(lock);

    MSG1(proc->trace,"%s Send resume\n", proc -> procname.c_str());
    proc -> status = ACTIVE;
    proc -> waiting_cnxt = 0;

  }


  if (cpp -> elem_list[elem_no].closed) {
    value = 1;
    goto retn;
  }
  if (cnp -> nonterm_upstream_proc_count == 0) {
    value = 1;
    goto retn;
  }

  if (IPptr -> owner != proc)
    printf("IP header corrupted: '%s'\n", proc->procname.c_str());
  IPptr -> owner = cnp;
  //optr = IPptr -> prev_IP;
  //qptr = IPptr -> next_IP;

  prevIP = cnp -> last_IPptr;
  if (prevIP != 0)
    prevIP -> next_IP = IPptr;
  else
    cnp -> first_IPptr = IPptr;

  cnp -> last_IPptr = IPptr;
  IPptr -> next_IP = 0;


  if ((cnp -> IPcount) == 0)   /* if it was empty, enable fedproc */
    {
      sptr = cnp -> fed_proc;

      if (sptr -> status == NOT_STARTED || sptr -> status == DORMANT) {

	if (sptr -> begin_port == 0) {
							
	  if (sptr -> trace)
	    printf("%s Initiated\n",sptr -> procname.c_str());
	  //sptr -> status = ACTIVE;
	  sptr -> activate();
	}
	else
	  if (sptr -> begin_port -> elem_list[0].gen.connxn == cnp) {
					
	    if (sptr -> trace)
	      printf("%s Initiated\n",sptr -> procname.c_str());
					
	    sptr ->activate();
	    proc -> int_pe.cpptr = proc -> begin_port;
	    proc -> value = thzrecv(proc, &proc -> int_ptr,  //????
				    &proc -> int_pe, 0, &size, type);
	    proc -> value = thzdrop(proc, &proc -> int_ptr);
	  }
      }
      else 	
	cnp->buffer_not_empty.notify_all();		
    }
	
  ++cnp -> IPcount;
  MSG1(proc->trace,"%s Send end\n", proc -> procname.c_str());
  *ptr = 0;
  value = 0;
  proc -> owned_IPs--;
 retn:
  //cnp->lock.unlock();
  //cnp -> lock.~unique_lock();	
  proc -> network -> active = true;
  return(value);
}
