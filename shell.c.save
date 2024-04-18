#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	char *args[ARG_MAX];
	int i;
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			return (0);
		}
		line[read - 1] = '\0';

		i = 0;
		token = strtok(line, " ");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid = fork();
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				printf("%s: No such file or directory\n", line);
				exit(EXIT_FAILURE);
			}
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
	free(line);
	return (0);
}
