#include "shell.h"

void read_command(char **line, size_t *len)
{
	ssize_t read;

	printf("#cisfun$ ");
	fflush(stdout);
	read = getline(line, len, stdin);
	if (read == -1)
	{
		free(*line);
		exit(EXIT_SUCCESS);
	}
	(*line)[read - 1] = '\0';
	while (read > 1 && (*line)[read - 2] == ' ')
	{
		(*line)[read - 2] = '\0';
		read--;
	}
}
