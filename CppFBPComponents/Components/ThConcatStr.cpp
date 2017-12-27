#include "compsvcs.h"

// This component receives all IPs from input port element 0, then from element 1, then from 2, and so forth...

// This is totally different from the Concat's in JavaFBP, C#FBP and JSFBP - probably the name should be changed... 

THRCOMP ThConcatStr(anchor proc_anchor)
{
	void *ptr;
	//void *ptr2;
	int value;
	long size;
	std::string type;
	port_ent port_tab[2];

	value = dfsdfpt(proc_anchor, 2, port_tab,"IN","OUT");

	int no = dfselct(proc_anchor, &port_tab[0]);

	for (int i = 0; i < no; i++) {
		value = dfsrecv(proc_anchor, &ptr, &port_tab[0], i, &size, &type);
		while (value == 0) {

			value = dfssend(proc_anchor, &ptr, &port_tab[1], 0);  				
			value = dfsrecv(proc_anchor, &ptr, &port_tab[0], i, &size, &type);
		}

	}
	return(0);

}
