#include "shell.h"

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
		while (wait(NULL) != pid);
	}
}
