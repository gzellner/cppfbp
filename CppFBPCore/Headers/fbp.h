
#include <stdarg.h>

#define MSG0(text)  {printf(text); \

#define MSG1(text,par1)  {printf(text, par1); \
						 }
// Define 2-parameter macro for tracing

#define MSG2(text,par1,par2) {printf(text, par1, par2); \
					  }

// Define 3-parameter macro for tracing

#define MSG3(text,par1,par2,par3) { printf(text, par1, par2, par3); \
				   }


