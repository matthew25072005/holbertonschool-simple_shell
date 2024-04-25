#include "shell.h"

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
