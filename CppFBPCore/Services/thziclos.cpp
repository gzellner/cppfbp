#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cppfbp.h"
#define INPUT 0
#define OUTPUT 1



void thziclos(Process *pptr, Port  * cpp, int elem_no)
{
	Process *sptr;
	//Port *cpp;
	//Cnxt *cnp;
	IPh   *IPptr;
	IPh   *nextIP;

	//cpp = (cp *)peptr -> cpptr;
	//if (peptr -> ret_code == 2)
	//	return(2);     

	//if (cpp -> elem_list[elem_no].closed)
	//	return(1);

	//if (pptr->trace) MSG1("%s Close\n",pptr -> procname);

	if (cpp -> elem_list[elem_no].is_IIP) {
					cpp -> elem_list[elem_no].closed = true;
					return;
	}

	Cnxt * cnp = cpp -> elem_list[elem_no].gen.connxn;
	
	//int value = 0;
	boost::unique_lock<boost::mutex> lock (cnp -> mtx); 
	
	if (cpp -> direction == INPUT) {
		// Closing an input port
		if (pptr->trace) MSG1("%s Close input\n",pptr -> procname);
		//Cnxt * cnp = cpp -> elem_list[elem_no].gen.connxn;
		if (cnp -> closed) {
			//value = 1;
			goto retn;
		}

		cnp -> nonterm_upstream_proc_count = 0;
		cnp -> closed = true;
		//sptr = cnp -> procs_wtg_to_send;
		//while (sptr != 0)   {
			//cnp -> procs_wtg_to_send = sptr -> next_proc;

			//sptr -> status = ACTIVE;
			//sptr = cnp -> procs_wtg_to_send;
			IPptr = cnp -> first_IPptr;
			while (IPptr != 0) {
				nextIP = IPptr -> next_IP;
				//thzfree(IPptr, pptr);
				free(IPptr);
				IPptr = nextIP;
				if (pptr -> trace)
					printf("%s IP discarded\n", pptr -> procname);
			}
			cnp -> first_IPptr = 0;
			cnp -> last_IPptr = 0;
			cnp -> IPcount = 0;
			cnp->buffer_not_full.notify_all();
		//}

	}

	else {
		// Closing an output port
		if (pptr->trace) MSG1("%s Close output\n",pptr -> procname);
		//Cnxt * cnp = cpp -> elem_list[elem_no].gen.connxn;
		cnp -> nonterm_upstream_proc_count--;
		sptr = cnp -> fed_proc;
		//term_now = true;
		if (sptr -> begin_port != 0 &&
			sptr -> begin_port -> elem_list[0].gen.connxn == cnp) {
				cnp -> nonterm_upstream_proc_count = 0;
				//term_now = false;
		}

		if (cnp -> nonterm_upstream_proc_count == 0) {
			
			cnp -> closed = true;
			if (sptr -> status == NOT_STARTED || sptr -> status == DORMANT)
			sptr -> activate();
			else 
				cnp->buffer_not_empty.notify_all();
		}
	}

	cpp -> elem_list[elem_no].closed = true;
	lock.unlock();
    lock.~unique_lock();
	if (pptr->trace) MSG1("%s Close end\n", pptr -> procname);
	
retn:
	return;
}

