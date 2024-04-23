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
        fflush(stdout);
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        line[read - 1] = '\0';  // remove newline at the end

        // Ignore trailing spaces
        while (read > 1 && line[read - 2] == ' ')
        {
            line[read - 2] = '\0';
            read--;
        }

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            exit(EXIT_SUCCESS);
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

        pid = fork();
        if (pid == 0)
        {
            if (execve(args[0], args, NULL) == -1)
            {
                perror(line);
                _exit(EXIT_FAILURE);
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
