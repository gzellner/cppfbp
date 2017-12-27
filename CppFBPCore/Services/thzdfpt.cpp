
#include <stdio.h>
#include <string.h>
#include "cppfbp.h"

int thzdfpt(Process *pptr, int port_count, port_ent *peptr)
{
  Port *cpp;
  int i;

  MSG1(pptr->trace,"%s DFPT Start\n", pptr->procname.c_str());
  for (i = 0; i < port_count; i++)
    {
      cpp = pptr -> in_ports;
      while (cpp != nullptr) {
	if ((peptr+i)-> port_name == cpp -> port_name) break;
	cpp = cpp -> succ;
      }
      if (cpp != nullptr){
	(peptr+i)-> cpptr = cpp;
	(peptr+i) -> elem_count = cpp -> elem_count;
	(peptr+i)-> ret_code = 0;
      }
      else {
	cpp = pptr -> out_ports;
	while (cpp != nullptr) {
	  if ((peptr+i) -> port_name == cpp -> port_name) break;
	  cpp = cpp -> succ;
	}
	if (cpp == nullptr)
	  (peptr+i)-> ret_code = 2;
	else {
	  (peptr+i)-> cpptr = cpp;
	  (peptr+i)-> elem_count = cpp -> elem_count;
	  (peptr+i)-> ret_code = 0;
	}
      }
    }
  MSG1(pptr->trace,"%s DFPT End\n", pptr->procname.c_str());

  return(0);
}
