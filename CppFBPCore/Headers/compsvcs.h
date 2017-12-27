


#pragma once

#include <string>
#include "thxanch.h"

#define THRCOMP int 

int dfscrep(anchor proc_anchor, void **ptr, long size, std::string *type);
   int dfssend(anchor proc_anchor, void **ptr, port_ent *peptr,
       int elem_no);
   int dfsrecv(anchor proc_anchor, void **ptr, port_ent *peptr,
       int elem_no, long *size, std::string *type);
   int dfsdrop(anchor proc_anchor, void **ptr);
int dfsdfpt(anchor proc_anchor, int port_count, port_ent *peptr, ...);
   int dfspush(anchor proc_anchor, void **ptr);
   int dfspop(anchor proc_anchor, void **ptr, long *size, std::string *type);
   int dfsclos(anchor proc_anchor, port_ent *peptr,
       int elem_no);
   int dfstest(anchor proc_anchor);
   long dfsgsize(anchor proc_anchor, void **ptr);
   int dfselct(anchor proc_anchor, port_ent *peptr);

   int dfssendc(anchor proc_anchor, void **ptr, std::string *port);
   int dfsrecvc(anchor proc_anchor, void **ptr, std::string *port, long *size, std::string *type);

   int dfsclosc(anchor proc_anchor, std::string *port);
   int dfselctc(anchor proc_anchor, std::string *port);
  
 
