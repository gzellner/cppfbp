#pragma once

// In what follows, IP means Information Packet  


struct _IPh {                 //  Information Packet header
  //-------------------------------------
  char  *type;            //  ptr to string specifying IP 'type'
  struct _IPh   *next_IP; //  ptr to next IP in connection or stack
  struct _IPh   *prev_IP; //  ptr to previous IP in connection or
  //      stack 
  void  *owner;           //  ptr to 'owner' - may be process or
  //      connection
  int reserved;              //  padding
  bool on_stack;         //  IP is on stack - TRUE or FALSE
  long IP_size;              //  size of IP - excluding header
} ;

typedef  _IPh IPh;



struct _IP {                  //  Information Packet
  //--------------------------------------
  struct _IPh IP_header;     //    header, followed by 0 - 32767 
  char unsigned datapart[32767];  //   bytes
} ;

typedef  _IP IP;


#define guard_value 219  /* solid rectangle */

