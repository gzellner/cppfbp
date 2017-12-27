#include <stdio.h>
#include <string.h>
#include "cppfbp.h"

int thzpop(Process *pptr, void **ptr, long *size, std::string &type)
{
  //process *sptr;
  IPh   *IPptr;
  //IPh   *optr;
  IP   *tptr;
  //int value;


  MSG1(pptr->trace,"%s Pop start\n", pptr -> procname.c_str());

  if ((IPptr = pptr -> stack) == 0)
    return(2);
  pptr -> stack = IPptr -> next_IP;
  tptr = (IP *) IPptr;
  if (tptr -> datapart[IPptr -> IP_size] != guard_value)
    printf("Guard byte corrupted: '%s'\n", pptr -> procname.c_str());
  if (IPptr -> owner != pptr)
    printf("IP header corrupted: '%s'\n", pptr->procname.c_str());
  if (! IPptr -> on_stack)
    printf("IP not on stack: '%s'\n", pptr->procname.c_str());

  *ptr = tptr -> datapart;
  *size = IPptr -> IP_size;
  type = IPptr -> type->c_str();
  //if ((optr = pptr -> first_owned_IP) != 0)
  //    optr -> prev_IP = IPptr;
  //IPptr -> next_IP = optr;
  IPptr -> next_IP = 0;
  IPptr -> prev_IP = 0;
  //pptr -> first_owned_IP = IPptr;
  IPptr -> owner = pptr;
  IPptr -> on_stack = false;
  MSG1(pptr->trace,"%s Pop end\n", pptr -> procname.c_str());
  pptr -> owned_IPs++;
  return(0);
}
