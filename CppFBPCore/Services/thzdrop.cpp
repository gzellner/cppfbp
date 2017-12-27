#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "cppfbp.h"

int thzdrop(Process *proc, void **ptr)
{
   IPh   *IPptr;
   IP   *tptr;
   
   MSG1(proc->trace,"%s Drop start\n", proc -> procname.c_str());
   IPptr = (IPh   *) *ptr - 1;       /* back up size of header */
   tptr = (IP   *) IPptr;
   if (tptr -> datapart[IPptr -> IP_size] != guard_value)
     printf("Guard byte corrupted - %s\n", proc->procname.c_str());
   if (IPptr -> owner != proc)
     printf("IP header corrupted - %s\n", proc->procname.c_str());
   if (IPptr -> on_stack)
     printf("IP on stack - %s\n", proc->procname.c_str());

   boost::lock_guard<boost::mutex> lock(proc -> network -> heapmtx);
   free(IPptr);
   //lock.~lock_guard();
    
   proc -> owned_IPs--;
   MSG1(proc->trace,"%s Drop end\n",proc -> procname.c_str());
   *ptr = 0;
   return(0);
}
