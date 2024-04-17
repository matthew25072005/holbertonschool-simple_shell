#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

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
		if (system(line) == -1)
		{
			printf("%s: No such file or directory\n", line);
		}
	}
	free(line);
	return (0);
}
