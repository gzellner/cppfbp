

/** 
This is the C++FBP main-line, working from a set of linked, fixed-layout, structures encoding the relationships 
between processes, connections, ports and IIPs - they will be referred to as fixed-format network definitions (FFNDs).

*/

#include <stdarg.h>

#include "thxdef.h"
#include "cppfbp.h"


	void   CppFBP(label_ent * label_blk, bool dynam, FILE * fp, bool timereq) {

		Network * network = new Network;
		_anchor anch;
		anch.reserved = NULL;
		network->go(label_blk, dynam, fp, timereq, anch);
		delete network;
	}


