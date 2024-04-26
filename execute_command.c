#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: Null terminated list of arguments
 *
 * This function takes a list of arguments where the first argument is
 * the command to be executed and the rest are the arguments to this command.
 * It searches for the command in the system's PATH and executes it.
 * If the command is "exit", it exits the shell.
 * If the command cannot be found, it prints an error message.
 */

void execute_command(char **args)
{
	pid_t pid;

	if (strcmp(args[0], "exit") == 0)
	{
		free(args[0]);
		exit(EXIT_SUCCESS);
	}

	pid = fork();
	if (pid == 0)
	{
		char *abs_cmd = search_path(args[0]);

		if (abs_cmd != NULL)
		{
			if (execve(abs_cmd, args, NULL) == -1)
		{
			perror(abs_cmd);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("%s: command not found\n", args[0]);
	}

	free(abs_cmd);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		while (wait(NULL) > 0)
		{
			/* empty loop body */
		}
	}
}
