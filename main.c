#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * This function is the entry point for the shell program. It reads commands
 * from the standard input, parses them into arguments, and then executes the
 * command. It continues to do this in a loop until the user types "exit".
 *
 * Return: 0 on success, otherwise the exit status of the last command executed
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[ARG_MAX];

	while (1)
	{
		read_command(&line, &len);
		parse_command(line, args);
		execute_command(args);
	}
	free(line);
	return (0);
}
