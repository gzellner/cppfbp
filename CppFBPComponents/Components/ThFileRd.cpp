//#pragma comment(lib, "CppFBPCore")

/* THFILERD is a DOS file reader.  It accepts a filename as an input on port
OPT, reads the file, and for every record puts out an entity on
port OUT.
CALLING THFILERD:
'FILENAME.EXT' -> OPT read_input_file OUT -> output data stream,
read_input_file(THFILERD);
LIMITATIONS:
FILENAME is limited to 256 bytes including extension. (this is less
restrictive than DOS, so will not matter.
Input records must be less than 4096 bytes or they will be segmented.
If they are segmented it may be difficult to re-assemble them.
DEFAULTS:
NONE.  The filename is required.  A message will be produced if it is
not given.
*/

#include <stdio.h>
#include <string.h>
#include "compsvcs.h"  

THRCOMP ThFileRd(_anchor proc_anchor) {


		void *ptr;
		char fname[256];
		char string[4096];
		int value;
		long size;
		char *type;
		size_t len;
		port_ent port_tab[2];
		FILE *f;
		char A[2] = {"A"};

		printf("Read started!\n");
		
		value = dfsdfpt(proc_anchor, 2, port_tab, "OPT", "OUT");

		/* read in the filename and open the input file
		*/
		value = dfsrecv(proc_anchor, &ptr, &port_tab[0], 0, &size, &type);
		memcpy(fname, ptr, size);
		fname[size] = '\0';

		if ((f = fopen(fname, "r")) == NULL) {
			fprintf(stderr, "Cannot open file %s!\n", fname);
			return(8);
		}
		value = dfsdrop(proc_anchor, &ptr);

		/* read records from the input file and create entities from them.  If the
		input records are longer than 4096 bytes, they will be segmented and put out
		as a series of 4096 byte IPs.
		*/
		while ((fgets(string, 4096, f)) != NULL) {
			len = strlen(string);
			if (string[len - 1] == '\n')
				len = len - 1;
			value = dfscrep(proc_anchor, &ptr, static_cast<long>(len), A);
			memcpy(ptr, string, len);
			value = dfssend(proc_anchor, &ptr, &port_tab[1], 0);
		}
		fclose(f);
		return(0);
	}
