#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define PROMPT "#cisfun$ "

int main(void)
{
    char cmd[MAX_CMD_LEN];
    pid_t pid;
    int status;

    while (1)
    {
        printf(PROMPT);
        if (fgets(cmd, sizeof(cmd), stdin) == NULL)
        {
            printf("\n");
            exit(0);
        }

        cmd[strlen(cmd) - 1] = '\0';

        if (strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }

        pid = fork();
        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            char *argv[2];
            argv[0] = cmd;
            argv[1] = NULL;

            if (execve(cmd, argv, NULL) == -1)
            {
                perror(cmd);
            }
            exit(0);
        }
        else
        {
            wait(&status);
        }
    }

    return 0;
}
