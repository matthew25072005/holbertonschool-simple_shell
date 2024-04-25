#include "shell.h"

/**
* search_path - Searches for a command in the system's PATH
* @cmd: The command to search for
*
* This function takes a command and searches for it in the directories
* specified in the system's PATH environment variable. If the command is
* found, it returns the absolute path to the command. Otherwise,it returns NULL
* Return: The absolute path to the command if found, otherwise NULL
*/

char *search_path(char *cmd)
{
	char *PATH = getenv("PATH");
	char *dir = strtok(PATH, ":");
	char *abs_cmd = malloc(500);

	while (dir != NULL)
	{
		sprintf(abs_cmd, "%s/%s", dir, cmd);
		if (access(abs_cmd, F_OK) != -1)
			return (abs_cmd);
		dir = strtok(NULL, ":");
	}

	free(abs_cmd);
	return (NULL);
}
