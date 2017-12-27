#include "cppfbp.h"

int thzelctc(Process *proc, std::string &port)
{
  int elem_no = 0;
  std::string port_name;
  size_t p = port.find_first_of('[');
  size_t q;

  if (p == std::string::npos) 
    port_name = port;
  else {
    q = port.find_first_of(']', p);
    size_t n = q - p - 1;
    elem_no = std::stoi(port.substr(p+1, n));
    port_name = port.substr(p+1);
  }

  Port * cpp = proc -> in_ports;
  while (cpp != nullptr)
    {

      if (cpp -> port_name == port_name){
	break;
      }

      cpp = cpp -> succ;
    }
  if (cpp == nullptr) {
    cpp = proc -> out_ports;
    while (cpp != nullptr)
      {

	if (cpp -> port_name == port_name){
	  break;
	}

	cpp = cpp -> succ;
      }
    if (cpp == nullptr) {
      printf("%s Port %s not found\n", proc -> procname.c_str(), port_name.c_str());	
      return -1;
    }
  }
  return cpp -> elem_count;
}

int thzelct(Process *proc, port_ent *peptr)
{
  /*  This service returns the no. of elements in a cpp */

  Port * cpp = (Port *) peptr ->cpptr;
  return cpp->elem_count;

}
