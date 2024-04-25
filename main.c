#include "shell.h"

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
