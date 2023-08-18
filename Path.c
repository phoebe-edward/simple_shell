#include "main.h"
#define MAX_ARGS 10

int Path(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t read;
    int status;
    while (1)
    {
        printf(":) ");
        read = getline(&command, &len, stdin);

        if (read == -1)
        {
            printf("\n");
            break; // EOF (Ctrl+D)
        }

        if (read > 0 && command[read - 1] == '\n')
        {
            command[read - 1] = '\0';
        }

        /* Tokenize the command and arguments*/
        char *args[MAX_ARGS + 1];  // +1 for NULL terminator
        int argc = 0;
        char *token = strtok(command, " ");
        while (token != NULL && argc < MAX_ARGS)
        {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        if (argc > 0)
        {
            pid_t pid = fork();

            if (pid < 0)
            {
                perror("Forking failed");
                continue;
            }
            else if (pid == 0)
            {
                execvp(args[0], args);
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }
            else
            {
                
                waitpid(pid, &status, 0);
            }
        }
    }

    free(command);
    return 0;
}
