#pragma optimize( "", off )
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include "cppfbp.h"
#include <stdlib.h>

// #if __OS2__ == 1
// #define getc fgetc
// #undef  EOF
// #define EOF 0xff
// #endif 


#define TC(label,ch) { if (curr_char != ch) goto label; \
    *o_ptr = curr_char; o_ptr++;  \
    curr_char = getc(fp); }

#define TCO(label,ch) { if (curr_char != ch) goto label;  \
	curr_char = getc(fp); }

#define TCIO(label,ch)  {if (curr_char != ch) goto label; }

#define TA(label)  {  if (!isalpha(curr_char)) goto label; \
	*o_ptr = curr_char; o_ptr++;  \
	curr_char = getc(fp);}

#define TAO(label) {  if (!isalpha(curr_char)) goto label; \
	curr_char = getc(fp);}

#define TN(label)   { if (!isdigit(curr_char)) goto label; \
	*o_ptr = curr_char; o_ptr++;  \
	curr_char = getc(fp);}

#define TNO(label) {  if (!isdigit(curr_char)) goto label; \
	curr_char = getc(fp);}

#define CC    {   *o_ptr = curr_char; o_ptr++;  \
	curr_char = getc(fp);}

#define SC      { curr_char = getc(fp); }

char curr_char;

int scan_blanks(FILE *fp);
int scan_sym(FILE *fp, char * out_str);

label_ent * find_label(label_ent *label_tab, std::string &name, std::string &file, int label_count);
int thxgatrs(std::string &comp);
proc_ent *find_or_build_proc(std::string &nm);


proc_ent *proc_tab;
label_ent *label_curr;
char comp_name[255];
bool eof_found = false;
char eol = '\n';

/*
Currently, no label at beginning, and no subnet support.

thxscan scans off the free form network definition, generating fixed format definitions (FFNDs)

Unlike NoFlo, thxscan does not treat an end of line (EOL) as an end of clause

thxscan is either used by Thxgen to generate FFNDs, or by CppFBP in dynamic mode
*/

int thxscan(FILE *fp, label_ent *label_tab, char file_name[10])
{
	char *o_ptr;
	char out_str[255];
	//char fname[256];
	char out_num[8];
	size_t i, IIPlen, ret_code;
	std::string upstream_name;	
	std::string upstream_port_name;
	int upstream_elem_no;
	std::string procname;	


	proc_ent *proc_curr;
	//	proc_ent *proc_new;
	//	proc_ent *proc_find;
	cnxt_ent *cnxt_tab;
	cnxt_ent *cnxt_curr;
	cnxt_ent *cnxt_new;
	cnxt_ent *cnxt_hold;

//	label_ent *label_new;

	//int label_ct;
	bool eq_arrow;
	IIP *IIP_ptr;
	//FILE *fp2;
	//int res;

	ret_code = 0;
	
	curr_char = getc(fp);
	proc_tab = 0;
	cnxt_tab = 0;	
	label_curr = label_tab;

	label_curr->label = " ";
	label_curr->file = file_name;
	label_curr->ent_type = 'L';

	IIPlen = -1;
	out_num[0] = '\0';
	cnxt_hold = 0;
	

netloop:
	scan_blanks(fp);  // skip blanks, comments, etc.
	TCO(X0,'\'');
	goto Xs;
X0:
	if (scan_sym(fp, out_str) != 0) {  // this could be a network label or a process name...
		printf("Name error\n");
		ret_code = 4;
		goto exit;  
	}
	scan_blanks(fp);
	TCO(X2,':');
	label_curr->label = out_str;  // it was a label		  
	printf("Scanning Network: %s\n",out_str);

bigloop:	
	
	scan_blanks(fp);
	cnxt_hold = 0;
	IIPlen = -1;
	TCO(X1,'\'');
Xs:
	o_ptr = out_str;	
	goto get_rest_of_IIP;

X1:
	if (scan_sym(fp, out_str) != 0) {  // this must be a process name...
		printf("Name error\n");
		ret_code = 4;
		goto exit;  
	}
X2:
	procname = out_str;  
	std::cout << "Procname: " << procname << std::endl;
	if (cnxt_hold != 0) {
	  cnxt_hold -> downstream_name = procname;
	  cnxt_hold = 0;
	}

	proc_curr = find_or_build_proc(procname);

	scan_blanks(fp);	
	
	goto X3;

get_rest_of_IIP:    
	TCO(tbsl,EOF);  
	printf("EOF encountered within quoted string\n");
	ret_code = 4;
	goto exit;
tbsl:
	TCO(tbq,'\\');
	CC;
	goto get_rest_of_IIP;
tbq:
	TCO(copy,'\'');
	goto NQ2;
copy:
	CC;
	goto get_rest_of_IIP;
NQ2:   
	*o_ptr = '\0';
	IIPlen = static_cast<int>(o_ptr - out_str);	  
	IIP_ptr = (IIP *)malloc(IIPlen + 1);	  
	memcpy(IIP_ptr -> datapart, out_str, IIPlen);
	IIP_ptr -> datapart[IIPlen] = '\0';	  
	printf("IIP: %s\n", IIP_ptr -> datapart);
	scan_blanks(fp);
	//IIPlen = -1;
	goto tArrow;

 
	// scan off process name with optional component name

X3:
	TCO(NB1,'('); 
	scan_blanks(fp);
	TCO(rest_of_comp, ')');
	goto NN2;
rest_of_comp:	
	//scan_blanks(fp);
	TCO(NQ6,'"');           // this says that comp name may be surrounded by double quotes (not included in comp_name)
NQ6: 
	o_ptr = comp_name;      // if no data between brackets, comp_name will not be modified...

TB1: 
	TCO(NQ7, '"');
	scan_blanks(fp);

NQ7:  
	TCO(NB2, ')');
	goto NN2;
NB2:
	CC;
	goto TB1;

NN2:
	*o_ptr = '\0';

	if (strlen(comp_name) > 0) {
	  proc_curr -> comp_name = comp_name;
	  std::cout << "Comp name: " << comp_name << std::endl; 
	}

NB1: 
	// comp scanned off, if any
	upstream_name = procname;	    // in case this proc is the upstream of another arrow
	
	scan_blanks(fp);


	TCO(NQ1,'?');
	proc_curr->trace = 1;
NQ1: 

	//if (cnxt_hold != 0) {
	//  strcpy(cnxt_hold->downstream_name, procname);
	//  cnxt_hold = 0;
	//}

	
	scan_blanks(fp);


	//o_ptr = out_str;
	//TC(outport,'*');     /* automatic port */
	//*o_ptr = '\0';
	//IIPlen = -1;
	//goto GUy;

//outport:  -- same as upstream port
	
	//scan_blanks(fp);


	TCO(tsc,EOF);
	eof_found = true;
	goto nxtnet;

tsc:
	TCO(tiip,';'); 
nxtnet:
	// this is a fudge because multiple nets are not currently supported 
	IIPlen = -1;
	scan_blanks(fp);
	TCO(nextnet,EOF); 
	goto exit;

tiip:	   
	IIPlen = -1;
	TCO(get_up_port,',');	
	
	scan_blanks(fp);
	goto bigloop; 

get_up_port:	
	o_ptr = out_str;
	TC(outport,'*');     /* automatic port */
	*o_ptr = '\0';
	
	goto GUy;

outport:
	if (scan_sym(fp,  out_str) != 0) {
		printf("Name error\n");
		ret_code = 4;
		goto exit;  
	}
GUy:
	scan_blanks(fp);
	
	upstream_port_name = out_str;
	std::cout << "Upstream port: " << out_str << std::endl;
	upstream_elem_no = 0;
	TCO(tArrow,'[');
	o_ptr = out_num;
GNx:  
	TN(NNx);
	goto GNx;
NNx:  
	TCO(elemerr,']');
	*o_ptr = '\0';
	upstream_elem_no = atoi(out_num);
	scan_blanks(fp);

tArrow: 
	scan_blanks(fp);
	eq_arrow = false;
	TCO(tEq,'-');
	goto tGr;
tEq: 
	TCO(nArrow,'=');
	eq_arrow = true;
tGr:
	TCO(nArrow,'>');
	printf("Arrow\n");
	cnxt_new = (cnxt_ent *) malloc (sizeof(cnxt_ent)); 
	cnxt_new->succ = 0;
	cnxt_new->dropOldest = false;
	if (cnxt_tab == 0) {
		cnxt_tab = cnxt_new;
		label_curr ->cnxt_ptr = cnxt_tab;		
		cnxt_curr = cnxt_tab;
	}
	else {		  
		cnxt_curr -> succ = cnxt_new;
		cnxt_curr = cnxt_new;
	}

	cnxt_hold = cnxt_new;
	if (IIPlen != -1) {
		cnxt_hold->upstream_name = "!";
		cnxt_hold->upstream_port_name = "";
		cnxt_hold->gen.IIPptr = IIP_ptr;
	}
	else {
		cnxt_hold -> upstream_name = upstream_name;
		cnxt_hold -> upstream_port_name = upstream_port_name;

		cnxt_hold -> upstream_elem_no = upstream_elem_no;
	}
	cnxt_hold->capacity = -1;
	scan_blanks(fp);
	TCO(ncap,'(');
	o_ptr = out_num;
GNz: 
	TN(NNz);
	goto GNz;
NNz: 
	TCO(caperr,')');
	*o_ptr = '\0';
	cnxt_hold->capacity = atoi(out_num);
	scan_blanks(fp);
	goto ncap;
caperr: 
	printf("Capacity error\n");
	ret_code = 4;
	goto exit;
ncap:
	cnxt_hold->downstream_elem_no = 0;

	/* Scan off downstream port name */
	o_ptr = out_str;
	TC(Y2a,'*');       /* automatic port */
	*o_ptr = '\0';
	cnxt_hold->downstream_port_name = out_str;  /* ext. conn */
	goto is_outport;
Y2a: 
	if (scan_sym(fp,  out_str) != 0) {
	  std::cout << "Downstream port name error for " <<
	    cnxt_hold->upstream_name << " " <<
	    cnxt_hold->upstream_port_name << std::endl;
		ret_code = 4;
		goto exit;  
	}
	cnxt_hold->downstream_port_name =  out_str;

is_outport:

	std::cout << "Downstream port: " << cnxt_hold->downstream_port_name << std::endl;

	scan_blanks(fp);
	TCO(X1,'[');
	o_ptr = out_num;
GNy: 
	TN(NNy);
	goto GNy;
NNy:  
	TCO(elemerr,']');
	*o_ptr = '\0';
	cnxt_hold->downstream_elem_no = atoi(out_num);
	//cnxt_hold = 0;
	scan_blanks(fp);
	goto X1;   

nextnet:
	scan_blanks(fp);
	
	if (eof_found) {
		label_curr -> succ = 0;   // temporary fix as we are only generating one network for now
		goto exit;
	}

	goto netloop;


elemerr:
	printf("Port element error\n");
	ret_code = 4;
	goto exit;

nArrow: 
	printf("No arrow found\n");
	ret_code = 4;
exit:
	printf("\nSummary:\n");
	proc_curr = proc_tab;
	while (proc_curr != 0) {	
	  std::cout << " Process: " << proc_curr -> proc_name << "(" << proc_curr -> comp_name << ")" << std::endl;
	  proc_curr = proc_curr -> succ;
	}

	cnxt_hold = cnxt_tab;
	while (cnxt_hold != 0) {
	  std::string up;
	  std::string down;
	  std::string elem;
		if (cnxt_hold -> upstream_name[0] != '!') {
			up = cnxt_hold -> upstream_port_name;
			if (up[0] != '*') {
				up += "[";				
				elem = cnxt_hold -> upstream_elem_no;
				up += elem;
				up += "]";
			}
			down = cnxt_hold -> downstream_port_name;
			if (down[0] != '*') {
				down += "[";
				elem = cnxt_hold -> downstream_elem_no;
				down += elem;
				down += "]";
			}
			std::cout << " Connection: " << cnxt_hold -> upstream_name << " " << up << " -> " << down << " " << cnxt_hold -> downstream_name << std::endl;
		}
		else {
			down = cnxt_hold -> downstream_port_name;
			if (down[0] != '*') {
				down += "[";
				elem = cnxt_hold -> downstream_elem_no;
				down += elem;
				down += "]";
			}
			std::cout << " IIP: -> " << down << " " << cnxt_hold -> downstream_name << std::endl;
			IIP_ptr = cnxt_hold -> gen.IIPptr;
			printf("    \'");
			auto j = strlen(IIP_ptr -> datapart);
			for (i = 0; i < j; i++)
				printf("%c",IIP_ptr -> datapart[i]);
			printf("\'\n");
		}
		cnxt_hold = cnxt_hold -> succ;
	}
	if (fclose(fp) != 0) {
		printf("Close error\n");
		if (ret_code == 0)
			ret_code = 2;
	}
	if (ret_code > 0) {
		// printf("Scan error\n");
		return(ret_code);
	}
	
	// printf("Scan finished\n");
	return (ret_code);
}

/* 

Scan off blanks or EOLs - returns: 
4 if EOF encountered in a comment
0 otherwise

*/

int scan_blanks(FILE *fp)
{
	//extern char curr_char;
	int res = 0;

	for (;;) {
sbs:
		TCO(not_blank,' ');
		continue;
not_blank: 
		TCO(not_EOL, '\n');
		continue;
not_EOL:
		TCO(ncom,'#');   // comment runs from #-sign to end of line
		for (;;) {
			TCO(tasu,EOF);
			//printf("EOF encountered within comment\n");
			//res = 4;
			goto exit;
tasu:
			TCO(nnl,eol);		
			break;
nnl:        SC;  // skip character
		}
		goto sbs;		
ncom:
		break;
		

	}
exit: 	
	return(res);

}

/*
Scan off a network label or process name (this is used for ports as well, as we don't know if a string is a port until later...)
*/
inline int scan_sym(FILE *fp, char * out_str)
{
	//extern char curr_char;
	char * o_ptr;
//	int i;

	o_ptr = out_str;
X4:
	TA(NA4);	
	goto X5;
NA4: 
	TN(NN4);
	goto X5;
NN4: 
	TC(NU4,'_');
	goto X5;
NU4:
	TCO(ES4,'\\');
    CC;
	
X5:
	goto X4;
ES4:
	*o_ptr = '\0';           
	return(0);
}

label_ent * find_label(label_ent *label_tab, std::string &name, std::string &file,  int label_count )
{
	label_ent * label_new;
	label_new = label_tab;
	while (label_new != 0){

		if (label_new -> label[0] == '\0') 
			continue;  
		if (label_new -> ent_type != 'L') 
			continue;  
		if ((label_new->label == name) &&
		    (label_new->file == "") ||
		    (label_new->file == file))
			break;
		label_new = label_new->succ;
	}
	return(label_new);
}

proc_ent * find_or_build_proc(std::string &name) {
	proc_ent * this_proc = proc_tab;	   
	proc_ent * last_proc = 0;
	while (this_proc != 0) {			
		if (this_proc->proc_name == name) break;	
		last_proc = this_proc;
		this_proc = this_proc->succ;
	}

	if (this_proc == 0)  {   // not found
		proc_ent * proc_new = (proc_ent *) malloc(sizeof(proc_ent));		   
		if (proc_tab == 0){
			proc_tab = proc_new;	
			label_curr->proc_ptr = proc_tab;
		}
		else {
			last_proc -> succ = proc_new;
		}

		this_proc = proc_new;

		//proc_curr->proc_name[0] = '\0';	
		this_proc-> succ = 0;
		this_proc-> composite = 0;
		this_proc-> faddr = 0;
		this_proc->proc_name = name;
		this_proc->trace = 0;
		this_proc->comp_name = "";
	}
	return this_proc;
}
