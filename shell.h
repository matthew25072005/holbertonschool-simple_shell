#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARG_MAX 64

char *search_path(char *cmd);
void read_command(char **line, size_t *len);
void parse_command(char *line, char **args);
void execute_command(char **args);

#endif

