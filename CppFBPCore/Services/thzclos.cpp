
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cppfbp.h"
#define INPUT 0
#define OUTPUT 1

void extern thziclos(Process *proc, Port  * cpp, int elem_no);

int thzclos(Process *proc, port_ent *peptr, int elem_no);

int thzclosc(Process *proc, std::string &port ){
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
	
  int value = thzclos(proc, &pe, elem_no);

  //free (pe);
  return value;
}

int thzclos(Process *proc, port_ent *peptr, int elem_no)
{
  //Process *sptr;
  Port *cpp;
  //Cnxt *cnp;
  //IPh   *IPptr;
  //IPh   *nextIP;

  cpp = (Port *)peptr -> cpptr;
  if (peptr -> ret_code == 2)
    return(2);     

  if (cpp -> elem_list[elem_no].closed)
    return(1);

  MSG1(proc->trace,"%s Close\n",proc -> procname.c_str());

  thziclos(proc, cpp, elem_no);

	
  cpp -> elem_list[elem_no].closed = true;

  MSG1(proc->trace,"%s Close end\n", proc -> procname.c_str());
  return(0);
}

