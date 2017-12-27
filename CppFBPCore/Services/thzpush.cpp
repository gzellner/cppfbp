#include <stdio.h>
#include <string.h>
#include "cppfbp.h"

int thzpush(Process *pptr, void **ptr)
{
   IPh   *IPptr;
   //IPh   *optr;
  // IPh   *qptr;
   IP   *tptr;

   MSG1(pptr->trace,"%s Push start\n", pptr -> procname.c_str());
   IPptr = (IPh   *) *ptr - 1;       /* back up size of header */
   tptr = (IP *)IPptr;
   if (tptr -> datapart[IPptr -> IP_size] != guard_value)
      printf("Guard byte corrupted: '%s'\n", pptr->procname.c_str());
   if (IPptr -> owner != pptr)
     printf("IP header corrupted: '%s'\n", pptr->procname.c_str());
   if (IPptr -> on_stack)
     printf("IP on stack: '%s'\n", pptr->procname.c_str());
   //optr = IPptr -> prev_IP;
   //qptr = IPptr -> next_IP;
  // if (optr != 0)
  //     optr -> next_IP = qptr;
  //   else
   //    pptr -> first_owned_IP = qptr;
  // if (qptr != 0)
  //   qptr -> prev_IP = optr;
   IPptr -> next_IP = pptr -> stack;
   pptr -> stack = IPptr;
   IPptr -> on_stack = true;
   MSG1(pptr->trace,"%s Push end\n",pptr -> procname.c_str());
   *ptr = 0;
   pptr -> owned_IPs--;
   return(0);
}
