
#pragma once

#include <string>

class Network
{
 public:
  std::string name;             // name of application

  Process* first_child_proc;  // ptr to first child process
  Process* first_child_comp;  // ptr to first child component

  struct _IPh   * alloc_ptr;  // ptr to allocated IP
  long alloc_lth;                // length of requested IP
  bool dynam;                     // DLLs being dynamically loaded (interpretive mode)

  Cnxt *first_cnxt;

  Cdl * latch;   // count down latch
  bool active;
	
  bool possibleDeadlock;
  bool deadlock;
  boost::mutex heapmtx;

   
  void waitForAll();
  void thxfcbs();
  bool deadlock_test();
  void go(label_ent *label_blk, bool dynam, FILE *fp, bool timereq, anchor proc_anchor); 
};


class SubNet:Network
{
 public:
  //	char name[32];             // name of subnet
  void go(label_ent *label_blk, bool dynam, FILE *fp, bool timereq, anchor proc_anchor); 
};

