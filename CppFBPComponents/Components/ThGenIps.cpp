
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "compsvcs.h"


  THRCOMP ThGenIps(anchor proc_anchor)
{
  void *ptr;
  char *p;
  std::string strng;
  int value, i;
  long size, count;
  std::string type;
  port_ent port_tab[3];
  std::string G = "G";

  value = dfsdfpt(proc_anchor, 3, port_tab,"COUNT","OUT","PREFIX");

  value = dfsrecv(proc_anchor, &ptr, &port_tab[0], 0, &size, &type);
  if (value > 0) {
     printf("THGENIPS: No number specified\n");
  //   dfsputs(proc_anchor, buffer);
     return(8);
     }
  strng.assign((char*)ptr,(size_t)size);
  strng[size] = '\0';
  count = std::stol(strng);

  value = dfsdrop(proc_anchor, &ptr);

  strng = "Testing ";
  value = dfsrecv(proc_anchor, &ptr, &port_tab[2], 0, &size, &type);
  if (value == 0) {
    strng.assign((char*)ptr,(size_t)size);
    strng[size] = '\0';
    value = dfsdrop(proc_anchor, &ptr);
  }
 // dfstest(proc_anchor);
  for (i = 0; i < count; i++) {
      value = dfscrep(proc_anchor, &ptr, 32, &G);
      strcpy((char *) ptr, strng.c_str());
      p = strchr((char *) ptr, '\0');
      sprintf(p, "%d", i);
      value = dfssend(proc_anchor, &ptr, &port_tab[1], 0);
      }
  return(0);
} 
