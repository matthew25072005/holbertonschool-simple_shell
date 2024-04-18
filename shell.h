#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARG_MAX 500

void execute_command(char *args[]);

#endif

