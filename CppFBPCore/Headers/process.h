
#pragma once

#include <string>

class Network;
class Process {             // process control block
  //--------------------------------------
 public:
  std::string procname;         // process name
  std::string compname;         // component name
  //Process *next_proc;   // ptr to next process in chain
  //       of ready processes (dynamic)
  //jmp_buf state;             // state of component - used by longjmp
  //    from scheduler back to component 
  Network *network;            // ptr to application control block
  Process *next_proc;  // ptr to next sibling process
  //   within subnet (static)
  Process *mother_proc;  // ptr to 'mother' process 
  Port *in_ports;        // ptr to first input port control block
  Port *out_ports;       // ptr to first output port control block
  //struct _IPh   *first_owned_IP;   // ptr to first IP owned by this
  //     process 
  Port *begin_port;      // ptr to 'beginning' port - if specified,
  //   process is delayed until IP arrives
  //   at this port
  Port *end_port;        // ptr to 'ending' port - if specified,
  //   process sends a signal to this port
  //   when it finally terminates  
  port_ent int_pe;   // 'port_ent' block internal to process
  //    control block  - allows 'ending' port
  //    logic to use THZSEND
  void *int_ptr;             // holds ptr to IP created by 'ending'
  //    port logic 
  int value;                 // holds return code from 'ending' port
  //    call to THZSEND

  //int ( __stdcall *faddr) (_anchor anch);   // address of code to be
  //     executed by this process
	
  int (*faddr)(anchor anch);     // address of code to be
  //     executed by this process

  anchor proc_anchor;  // anchor to be passed to service calls
  IPh   *stack;   //  ptr to first IP in process stack -
  //     managed by THZPUSH and THZPOP
  char status;               //  status of process execution:
  //     values defined in #defines below

  Cnxt * waiting_cnxt;   // connection process is waiting on
  bool trace;            //  trace required for process
  //bool terminating;      //  process is terminating
  bool must_run;         //  process must run at least once
  //unsigned has_run;          //  process has run at least once
  bool composite;        //  process is 'mother' of a subnet

  long owned_IPs;       // number of owned IPs
  bool self_starting = 0; /// FALSE

  void run();

  void dormwait();
  int run_test();

  bool readyToGo;
  boost::thread thread;   
  boost::condition canGo;
  boost::mutex mtx;


  /* following #defines are possible values of 'status' above */

#define NOT_STARTED           ' '    // not initiated
#define ACTIVE                'A'    // active
#define DORMANT               'D'    // waiting to be triggered
#define SUSPENDED_ON_SEND     'P'    // suspended on send 
#define SUSPENDED_ON_RECV     'G'    // suspended on receive
  //#define INITIATED             'I'    // initiated
  //#define READY_TO_RESUME       'R'    // ready to resume
#define TERMINATED            'T'    // terminated


 Process() : faddr(nullptr), readyToGo(false) {
    Process::status = NOT_STARTED ;		
  }

	 
  void activate(); 
	 
	

};


