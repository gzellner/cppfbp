#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "cppfbp.h"
    
#define TC(label,ch)  if (curr_char != ch) goto label;	\
  *o_ptr = curr_char; o_ptr++;				\
  curr_char = getc(fp);

#define TCO(label,ch)  if (curr_char != ch) goto label;	\
  curr_char = getc(fp);

#define TA(label)    if (!isalpha(curr_char)) goto label;	\
  *o_ptr = curr_char; o_ptr++;					\
  curr_char = getc(fp);

#define TAO(label)   if (!isalpha(curr_char)) goto label;	\
  curr_char = getc(fp);

#define TN(label)    if (!isdigit(curr_char)) goto label;	\
  *o_ptr = curr_char; o_ptr++;					\
  curr_char = getc(fp);

#define TNO(label)   if (!isdigit(curr_char)) goto label;	\
  curr_char = getc(fp);

#define CC       *o_ptr = curr_char; o_ptr++;	\
  curr_char = getc(fp);

#define SC       curr_char = getc(fp);

void  scan_blanks(FILE *fp);

extern char curr_char;


int thxgatrs(std::string &comp) {

  char *o_ptr;
  char out_str[256];
  int atr = 0;
  std::string fname;
  FILE *fp = NULL;

  fname = comp;
  fname += ".atr";
  FILE* pFile;
  pFile = fopen(fname.c_str(),"r");
	   
  if (pFile == NULL)
    return(-1);

  do {curr_char = getc(fp);} while (curr_char == '\n');

  o_ptr = out_str;
  scan_blanks(fp);
  TCO(nEOF,EOF);
  goto exit;

 nEOF: for (;;) {
    TA(nA);
    continue;
  nA:      TN(nN);
    continue;
  nN:      TC(nus,'_');
    continue;
  nus:     break;
  }
  *o_ptr = '\0';
  if (strcmp(out_str,"MUST_RUN") == 0 ||
      strcmp(out_str,"Must_run") == 0 ||
      strcmp(out_str,"must_run") == 0)
    atr = true;
  else
    atr = false;
  scan_blanks(fp);

 exit: fclose(fp);
  return(atr);
}

 
// void scan_blanks(FILE *fp)
// {
//   for (;;) {
//     TCO(not_blank,' ');
//     continue;
//   not_blank: TCO(exit,'\n');
//   }
//  exit: return;
// }      
