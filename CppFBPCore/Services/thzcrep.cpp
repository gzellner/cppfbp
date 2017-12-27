
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "cppfbp.h"



int thzcrep(Process *pptr, void **ptr, long IPsize, std::string &type)
{

	/*  This service returns the data part of an IP - if info is needed from the header,
	you have to back up over the length of the header */
	
   long totsize;
   IPh   *IPptr;
  
   IP   *tptr;
   
   MSG1(pptr->trace,"%s Crep start\n", pptr -> procname.c_str());
   if (IPsize > 64000 || IPsize < 0) {
     printf("Invalid IP size in CREP: %ld - %s\n", IPsize, pptr -> procname.c_str());
      return(8);
      }
   int i = sizeof(IPh);
   totsize = IPsize + i + 1;          // room for guard
    
   boost::lock_guard<boost::mutex> lock(pptr -> network -> heapmtx);
   IPptr = (IPh *) malloc(totsize);
   //lock.~lock_guard();

   IPptr -> IP_size = IPsize;
   IPptr -> owner = pptr;
   IPptr -> type = new std::string(type);
   
   IPptr -> next_IP = 0;
   IPptr -> prev_IP = 0;
   IPptr -> on_stack = false;
   //pptr -> first_owned_IP = IPptr;
   tptr = (IP *) IPptr;
   *ptr = tptr -> datapart;
   tptr -> datapart[IPsize] = guard_value;
   pptr -> owned_IPs++;
   MSG1(pptr->trace,"%s Crep end\n",pptr -> procname.c_str());
   return(0);
}
