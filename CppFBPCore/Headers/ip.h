#pragma once

#include <string>
// In what follows, IP means Information Packet  


struct IPh {                 //  Information Packet header
  //-------------------------------------
  std::string *type;            //  ptr to string specifying IP 'type'
  IPh   *next_IP; //  ptr to next IP in connection or stack
  IPh   *prev_IP; //  ptr to previous IP in connection or
  //      stack 
  void  *owner;           //  ptr to 'owner' - may be process or
  //      connection
  int reserved;              //  padding
  bool on_stack;         //  IP is on stack - TRUE or FALSE
  long IP_size;              //  size of IP - excluding header
} ;


struct IP {                  //  Information Packet
  //--------------------------------------
  IPh IP_header;     //    header, followed by 0 - 32767 
  char unsigned datapart[32767];  //   bytes
} ;


#define guard_value 219  /* solid rectangle */

