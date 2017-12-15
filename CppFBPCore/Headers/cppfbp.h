
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

#define MSG0(text)  {printf(text);		\

#define MSG1(text,par1)  {printf(text, par1);	\
  }
  // Define 2-parameter macro for tracing

#define MSG2(text,par1,par2) {printf(text, par1, par2); \
  }

  // Define 3-parameter macro for tracing

#define MSG3(text,par1,par2,par3) { printf(text, par1, par2, par3);	\
  }


