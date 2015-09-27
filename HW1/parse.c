/*
 * parse.c : use whitespace to tokenise a line
 * Initialise a vector big enough
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/* Parse a commandline string into an argv array. */
char ** parse(char *line) {
	
  	static char delim[] = " \t\n"; /* SPACE or TAB or NL */
  	int count = 0;
  	char * token;
  	char **newArgv;

  	/* Nothing entered. */
  	if (line == NULL) {
    	return NULL;
  	}
	if(line[strlen(line)-1]=='\n')
	line[strlen(line)-1]='\0';
  	/* Init strtok with commandline, then get first token.
     * Return NULL if no tokens in line.
	 *
	 * Fill in code.
     */
	token = strtok(line,delim);
	if(token == NULL)
		return NULL;



  	/* Create array with room for first token.
  	 *
	 * Fill in code.
	 */
	newArgv = (char**)malloc(sizeof(char*)*count+1);
  newArgv[count] = (char*)malloc(strlen(token)+1);
  strcpy(newArgv[count],token);

	


  	/* While there are more tokens...
	 *
	 *  - Get next token.
	 *	- Resize array.
	 *  - Give token its own memory, then install it.
	 * 
  	 * Fill in code.
	 */
while(1)
{
  count++;
  token = strtok(NULL,delim);
  if(token!=NULL)
  {
    newArgv = (char**)realloc(newArgv,sizeof(char*)*count+1);
    newArgv[count] = (char*)malloc(strlen(token)+1);
    strcpy(newArgv[count],token);
  }
  else 
	break;
}

  	/* Null terminate the array and return it.
	 *
  	 * Fill in code.
	 */
  newArgv=(char**)realloc(newArgv,sizeof(char*)*(count+1));
  newArgv[count]='\0';
  int i;
  for(i=0;newArgv[i]!='\0';i++)
  {
    printf("[%d] : %s\n",i,newArgv[i]);
  }

  	return newArgv;
}


/*
 * Free memory associated with argv array passed in.
 * Argv array is assumed created with parse() above.
 */
void free_argv(char **oldArgv) {

	int i = 0;
	/* Free each string hanging off the array.
	 * Free the oldArgv array itself.
	 *
	 * Fill in code.
	 */
  for(i=0;oldArgv[i]!='\0';i++)
    free(oldArgv[i]);
  free(oldArgv);
}
