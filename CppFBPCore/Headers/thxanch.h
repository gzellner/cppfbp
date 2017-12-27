#pragma once

#include <stdarg.h>

struct port_ent              // block representing port in process's
//   stack storage - this relates the
//   name used by the component code
//   to the actual port control
//   block (cp)  - set by THZDFPT
//------------------------------------
{
  std::string port_name;     // port name  (from THZDFPT's parameters)
  // following fields are set by THZDFPT
  //union {
  //void *reserved;   
  void *cpptr;   // - pointer to actual port control block (Port)
  //};
  int elem_count;         // - no. of elements in port control
  //     block: >1 implies array port
  int ret_code;           // - return code: 2 indicates port closed 
};

struct  anchor
{

  int (*svc_addr) (int, void * vptr, ...);
  void *reserved;
} ;

