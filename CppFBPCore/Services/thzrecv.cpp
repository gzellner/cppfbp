#include <stdio.h>
#include <string.h>
#include "cppfbp.h"
#include <stdlib.h>
#define INPUT 0
#define OUTPUT 1

int thzrecv(Process *proc, void **ptr, port_ent *peptr, int elem_no,
	    long *size, std::string &type);

int thzcrep(Process *proc, void **ptr, long IPsize, std::string &type);

int thzrecvc(Process *proc, void **ptr, std::string &port, 
	     long *size, std::string &type)
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

  pe.port_name == port_name;
  Port * cpp = proc -> in_ports;
  while (cpp != 0)
    {
		
      if (cpp -> port_name == port_name){
	break;
      }
		 
      cpp = cpp -> succ;
    }
  pe.cpptr = cpp;
  pe.elem_count = cpp -> elem_count;  
  pe.ret_code = 0;
	
  int value = thzrecv(proc, ptr, &pe, elem_no, size, type);

  //free (pe);
  return value;
}


int thzrecv(Process *proc, void **ptr, port_ent *peptr, int elem_no,
	    long *size, std::string &type)
{

  /*  This service returns the data part of an IP - if info is needed from the header,
      you have to back up over the length of the header */

  //Process *sptr;
  IPh   *IPptr;
  //IPh   *optr;
  IP   *tptr;
  int value = 0;
  Port *cpp;
  Cnxt *cnp;
  IIP *IIPptr;
  IPh   *created_IIP_ptr;
  void *created_ptr;
  std::string options = "OPTIONS";
  //extern void run(Process * proc);

  if (peptr -> ret_code == 2) {
    MSG1(proc->trace,"%s Recv from unconnected port\n", proc -> procname.c_str());
    return(2);
  }
  cpp = (Port *)peptr -> cpptr;
  MSG3(proc->trace,"%s Recv start %s[%d]\n", proc -> procname.c_str(),
       cpp -> port_name.c_str(), elem_no);

  if (cpp -> elem_list[elem_no].is_IIP) {
    IIPptr = cpp -> elem_list[elem_no].gen.IIPptr;
    auto j = strlen(IIPptr -> datapart);
    value = thzcrep(proc, &created_ptr, static_cast<int>(j + 1), options);
    created_IIP_ptr = (IPh   *) created_ptr - 1;
    memcpy (created_ptr, IIPptr -> datapart, j + 1);
    cpp -> elem_list[elem_no].closed = true;
    *ptr = created_ptr;
    *size = created_IIP_ptr -> IP_size;
    type = created_IIP_ptr -> type->c_str();
    cpp -> elem_list[elem_no].closed = true;

    MSG1(proc->trace,"%s Recv end\n", proc -> procname.c_str());
    return(0);
  }
	
  cnp = (Cnxt *) cpp -> elem_list[elem_no].gen.connxn;
  if (cnp == nullptr) return(2);
	
  //cnp ->lock.lock();
  //cnp -> lock = boost::unique_lock<boost::mutex> (cnp -> mtx); 
  boost::unique_lock<boost::mutex> lock (cnp -> mtx);
  if (cnp->closed && cnp->first_IPptr == nullptr) {     // connection closed AND drained
    MSG1(proc->trace,"%s Recv end of stream\n", proc -> procname.c_str());
    value = 2;
    goto retn;		
  }

  //if (proc -> trace) MSG3("%s Recv start %s[%d]\n", proc -> procname,
  //	cpp -> port_name, elem_no);

  if (elem_no < 0 || elem_no >= cpp ->elem_count) {
    printf("%s %s RECV Element Number negative or too high\n",
	   proc -> procname.c_str(), peptr -> port_name.c_str());
    value = 3;
    goto retn;			
  }
  if (cpp ->direction != INPUT) {
    printf("%s %s RECV Wrong direction\n",
	   proc -> procname.c_str(), peptr -> port_name.c_str());
    value = 3;
    goto retn;	
  }


  if (cpp -> elem_list[elem_no].closed) {
    MSG1(proc->trace,"%s Recv end no data\n", proc -> procname.c_str());
    value = 1;
    goto retn;
  }

			
  for (;;) {
		
    if (cnp -> first_IPptr != nullptr) goto X;

    if (cnp -> nonterm_upstream_proc_count == 0  /* ||
						    cpp -> elem_list[elem_no].closed */ )
      {
	MSG1(proc->trace,"%s Recv end no data\n", proc -> procname.c_str());
	value = 1;
	goto retn;
      }

    proc -> status = SUSPENDED_ON_RECV;
    proc -> waiting_cnxt = cnp;
    MSG1(proc->trace,"%s Recv susp\n", proc -> procname.c_str());
    cnp-> buffer_not_empty.wait(lock);
		
    MSG1(proc->trace,"%s Recv resume\n", proc -> procname.c_str());
    proc -> status = ACTIVE;
    proc -> waiting_cnxt = 0;
  }

 X: IPptr = cnp -> first_IPptr;
  if ((cnp -> first_IPptr = IPptr -> next_IP) == nullptr)
    cnp -> last_IPptr = nullptr;

  tptr = (IP *) IPptr;
  if (tptr -> datapart[IPptr -> IP_size] != guard_value)
    printf("Guard byte corrupted: '%s'\n", proc->procname.c_str());
  if (IPptr -> owner != cnp)
    printf("IP header corrupted: '%s'\n", proc->procname.c_str());
  *ptr = tptr -> datapart;
  *size = IPptr -> IP_size;
  type = IPptr -> type->c_str();
	
  IPptr -> next_IP = nullptr;
  IPptr -> prev_IP = nullptr;
	
  IPptr -> owner = proc;
  if (cnp ->IPcount == cnp -> max_IPcount)  
    cnp->buffer_not_full.notify_all();
	
  --cnp -> IPcount; 

  MSG1(proc->trace,"%s Recv end\n", proc -> procname.c_str());
  proc -> owned_IPs++;
  value = 0;
 retn:
	
  proc -> network -> active = true;
  return(value);
}
