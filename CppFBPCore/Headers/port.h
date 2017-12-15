
#pragma once

/* 
   cp and cp_elem handle the connections between a port and its owning process -
   each cp block is followed by an array of cp element blocks, each of which points at a connection (Cnxt), an IIP or zero
*/
struct Port_elem {     // port control block element -
  //   port is represented by port control block,
  //   followed by an array of port control block
  //   elements
  //-----------------------------------------------
  union cp_union {Cnxt *connxn; struct _IIP *IIPptr;}
    gen;     //  this field may point at a connection or
  //    an Initial IP (IIP)  or zero (i.e. unused)
  //  (an IIP is like a parameter - it is specified
  //    in the network, and then turned into an
  //    actual IP at run-time by THZRECV) 
  bool closed;   //  port element is closed
  bool is_IIP;   //  port element points at an IIP
  bool subdef;   //  port elem is defined in a subnet definition
} ;

typedef  Port_elem cp_elem;

class Port {          //  port control block (see above)
  //-----------------------------------------
 public:
  Port *succ;  // next port in input port chain or output
  //  port chain - these are separate chains
  char port_name[32];   // port name

  int elem_count;       //  count of elements in port 
  bool direction;   //  input/output port: TRUE = output
  //   0 = input
  //   1 = output 

  Port_elem elem_list[1]; // array of port control block elements

} ;

