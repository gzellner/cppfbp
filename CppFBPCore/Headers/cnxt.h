
#pragma once

#include <string>

class Process;
class Cnxt {                // control block for a connection
  //--------------------------------------  
 public:
  std::string name;             // name
  Process *fed_proc;         // ptr to process 'fed' by this connection
  //  (can only be one) 
	
  IPh   *first_IPptr;  // ptr to first IP in connection 
  IPh   *last_IPptr;   // ptr to last IP in connection
  Cnxt *succ;        // successor connection block - used for cleanup
  long max_IPcount;          // maximum count of IPs allowed = capacity
  long IPcount;              // actual count of IPs in connection
  int  total_upstream_proc_count;   // total no. of upstream port
  //      elements            
  int  nonterm_upstream_proc_count; // no. of upstream port elements
  //    which have not terminated - 0 means
  //    the connection is closed
	
  bool closed;


  //private:
  boost::condition_variable buffer_not_full, buffer_not_empty;
  boost::mutex mtx;
} ;

