#include "shell.h"

char *search_path(char *cmd)
{
	char *PATH = getenv("PATH");
	char *dir = strtok(PATH, ":");
	char *abs_cmd = malloc(500);

	while (dir != NULL)
	{
		sprintf(abs_cmd, "%s/%s", dir, cmd);
		if (access(abs_cmd, F_OK) != -1)
		return abs_cmd;
		dir = strtok(NULL, ":");
	}

		free(abs_cmd);
		return NULL;
}

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
		fflush(stdout);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		line[read - 1] = '\0';
		while (read > 1 && line[read - 2] == ' ')
		{
			line[read - 2] = '\0';
			read--;
		}
		i = 0;
		token = strtok(line, " ");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
		free(line);
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
	free(line);
	return (0);
}
