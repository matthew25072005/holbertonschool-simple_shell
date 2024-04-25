#include "shell.h"

/**
* parse_command - Parses a command line into arguments
* @line: The command line to parse
* @args: The array to store the parsed arguments
*
* This function takes a command line and parses it into separate arguments.
* The arguments are stored in the provided array. The array will be NULL
* terminated.
*/

void parse_command(char *line, char **args)
{
	int i = 0;
	char *token = strtok(line, " ");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
