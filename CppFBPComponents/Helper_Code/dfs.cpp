#include <stdarg.h>
   #include <string>
   #include <stdio.h>

   #include "thxanch.h"


 int const ZERO = 0;  // for testing
   int const ONE = 1;  //send
   int const TWO = 2;  //recv
   int const THREE = 3;  //crep
   int const FOUR = 4;  //drop
   int const FIVE = 5;   //dfpt
   int const SIX = 6;    //push
   int const SEVEN = 7;  //pop
   int const EIGHT = 8;  //close
   int const NINE = 9;   //gsize
   int const TEN = 10;   //elct

   int const ELEVEN = 11;  //sendc
   int const TWELVE = 12;  //recvc
   int const THIRTEEN = 13;  //closc
   int const FOURTEEN = 14;  //elctc
 
  

     int dfstest(anchor proc_anchor)
{
   int value;

   value = proc_anchor.svc_addr (ZERO, proc_anchor.reserved);
   return(value);
}

   int dfssend(anchor proc_anchor, void **ptr, port_ent *peptr,
       int elem_no)
{
   int value;

   value = proc_anchor.svc_addr (ONE, proc_anchor.reserved, ptr, peptr,
       elem_no)
       ;
   return(value);
}


   int dfsrecv(anchor proc_anchor, void **ptr, port_ent *peptr,
	       int elem_no, long *size, std::string *type)
{
   int value;

   value = proc_anchor.svc_addr (TWO, proc_anchor.reserved, ptr, peptr,
       elem_no, size, type);
   return(value);
}

int dfscrep(anchor proc_anchor, void **ptr, long size, std::string *type)
{
   int value;

   value = proc_anchor.svc_addr (THREE, proc_anchor.reserved, ptr, size,
       type);
   return(value);
}

 int dfsdrop(anchor proc_anchor, void **ptr)
{
   int value;

   value = proc_anchor.svc_addr (FOUR, proc_anchor.reserved, ptr);
   return(value);
}

 int dfsdfpt(anchor proc_anchor, int port_count, port_ent *peptr, ...)
{
   va_list ap;
   int i;
   int value;

   va_start (ap, peptr);
   for (i = 0; i < port_count; i++) {
     (peptr+i) -> port_name = (va_arg(ap, char*));
	//(peptr+i) -> reserved = 0;
	(peptr+i) -> elem_count = 0;
	(peptr+i) -> ret_code = 0;

	}
   va_end (ap);
   value = proc_anchor.svc_addr (FIVE, proc_anchor.reserved, port_count,
     peptr);
   return(value);
}

   int dfspush(anchor proc_anchor, void **ptr )
{
   int value;

   value = proc_anchor.svc_addr (SIX, proc_anchor.reserved, ptr);
   return(value);
}


int dfspop(anchor proc_anchor, void **ptr, long *size, std::string *type)
{
   int value;

   value = proc_anchor.svc_addr (SEVEN, proc_anchor.reserved, ptr, size, type);
   return(value);
}

   int dfsclos(anchor proc_anchor, port_ent *peptr,
       int elem_no)
{
   int value;

   value = proc_anchor.svc_addr (EIGHT, proc_anchor.reserved, peptr,
       elem_no);
   return(value);
}
   
   long dfsgsize(anchor proc_anchor, void **ptr) {
long size;

   size = proc_anchor.svc_addr (NINE, proc_anchor.reserved, ptr);
    
   return(size);
}

int dfselct(anchor proc_anchor, port_ent *peptr) {
int ct;

   ct = proc_anchor.svc_addr (TEN, proc_anchor.reserved, peptr);
    
   return(ct);
}
 
int dfssendc(anchor proc_anchor, void **ptr, std::string *port)
{
   int value;

   value = proc_anchor.svc_addr (ELEVEN, proc_anchor.reserved, ptr, port)
       ;
   return(value);
}


int dfsrecvc(anchor proc_anchor, void **ptr, std::string *port, long *size, std::string *type)
{
   int value;

   value = proc_anchor.svc_addr (TWELVE, proc_anchor.reserved, ptr, port, size, type);
   return(value);
}

int dfsclosc(anchor proc_anchor, std::string *port)
{
   int value;

   value = proc_anchor.svc_addr (THIRTEEN, proc_anchor.reserved, port);
   return(value);
}
int dfselctc(anchor proc_anchor, std::string *port) {
int ct;

   ct = proc_anchor.svc_addr (FOURTEEN, proc_anchor.reserved, port);
    
   return(ct);
}  
