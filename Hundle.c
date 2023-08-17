#include "main.h"
#define MAX_ARGS 10

/**
 * prompt - Reads user input and executes commands.
 *
 * Return: Always 0.
 */
int prompt(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("#cisfun$ ");
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

        // Tokenize the command and arguments
        char *args[MAX_ARGS + 2];  // +2 for command and NULL terminator
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
                if (access(args[0], X_OK) == 0)
                {
                    execve(args[0], args, NULL);
                    perror("Error executing command");
                    exit(EXIT_FAILURE);
                }
                else if (strcmp(args[0], "ls") == 0)
                {
                    char *ls_args[] = {"/bin/ls", "-la", NULL};
                    execve(ls_args[0], ls_args, NULL);
                    perror("Error executing command");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    printf("%s: No such file or directory\n", args[0]);
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }

    free(command);
    return 0;
}
