#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char* copy = (char*) malloc (sizeof(command)+1);
	int i = 0;
	while(*(command + i) != NULL) {
		copy[i] = *(command + i);//it even copies command's last char"\n"
		i++;
	}
	char* buf = (char*) malloc(sizeof(command)+1);
	buf = strtok(copy, " \t\n");

	*argv = (char**) malloc (sizeof(command) * sizeof(char));

	argv[0][0] = (char*) malloc(sizeof(char)*strlen(buf));

	memset(argv[0][0], NULL, sizeof(buf)+1);

	strcpy(argv[0][0], buf);

	*argc = 1;

	while(1) {
		buf = strtok(NULL, "! \n\t");

		if(buf == NULL)	break;

		argv[0][*argc] = (char*) malloc(sizeof(char) * strlen(buf));
		strcpy(argv[0][*argc], buf);
		(*argc)++;
	}

	free(buf);
}
