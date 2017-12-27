#include <stdarg.h>

#include "thxdef.h"
#include "cppfbp.h"


void   CppSub(label_ent * label_blk, bool dynam, FILE * fp, bool timereq, anchor proc_anchor) {
  anchor anch;
  
  Network * subnet = new Network;
  Process * mother = (Process *)proc_anchor.reserved;
  anch.reserved = mother;
  subnet->go(label_blk, dynam, fp, timereq, proc_anchor);
  delete subnet;
  
}
