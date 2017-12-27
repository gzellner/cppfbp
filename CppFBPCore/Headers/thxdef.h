#pragma once
#include <condition_variable>
#include <thread>
#include <mutex>
#include <list>
#include <string>

/* 
   external control blocks - used in network definitions
*/
 
#include "thxanch.h"

#define THRCOMP int 

struct _IIP
{
  char datapart[32767];
};

typedef  _IIP IIP;


struct proc_ent {
  proc_ent *succ;
  std::string proc_name;
  std::string comp_name;

  //int32_t (__stdcall *faddr) (_anchor anch);
  int (*faddr)(anchor anch);
	 
  void *proc_block;   // used as a temporary placeholder by thxbnet
  void * label_ptr;   // points to a label for subnets	 
  bool trace;
  bool composite;
  bool must_run;  // new - doesn't seem to hurt, even when CopyFile not modified!
};

class Cnxt;
struct cnxt_ent {
  cnxt_ent *succ;
  std::string upstream_name;       /* if 1st char is !,        */
  std::string upstream_port_name;     /* connxn points at IIP */
  int upstream_elem_no;
  std::string downstream_name;
  std::string downstream_port_name;
  int downstream_elem_no;
  union cnxt_union {IIP * IIPptr; Cnxt *connxn;} gen;
  int capacity;
  bool dropOldest;     // new - doesn't seem to hurt, even when CopyFile not modified!
};

struct label_ent {
  label_ent *succ;
  std::string label;
  std::string file;
  cnxt_ent *cnxt_ptr;
  proc_ent *proc_ptr;
  char ent_type;
};

#define THXDEF
#define TRACE true
#define COMPOS true
#define DYNAM true
#define TIME_REQ true
