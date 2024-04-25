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
