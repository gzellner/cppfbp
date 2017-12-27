
#include <boost/thread/condition.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/cv_status.hpp>

#include "thxanch.h"
#include "thxdef.h"
#include "cdl.h"
#include "ip.h"
#include "cnxt.h"
#include "port.h"
#include "process.h"
#include "network.h"

#define GEN_BOOST
//#define TRACE_M

#ifdef TRACE_M
#define MSG1(trace,text,par1) if(trace){printf(text, par1);}
  // Define 2-parameter macro for tracing
#else
#define MSG1(trace,text,par1)
#endif

#ifdef TRACE_M
#define MSG2(trace,text,par1,par2) if(trace){printf(text, par1, par2);}
#else
#define MSG2(trace,text,par1,par2)
#endif

#ifdef TRACE_M
#define MSG3(trace,text,par1,par2,par3) if(trace){printf(text, par1, par2, par3);}
#else
#define MSG3(trace,text,par1,par2,par3)
#endif


