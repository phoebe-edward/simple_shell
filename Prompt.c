#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

        if (access(command, X_OK) == 0)
        {
            pid_t pid = fork();

            if (pid < 0)
            {
                perror("Forking failed");
                continue;
            }
            else if (pid == 0)
            {
                char *args[] = {command, NULL};
                if (execve(command, args, NULL) == -1)
                {
                    perror("Error executing command");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                int status;
                waitpid(pid, &status, 0);
            }
        }
        else
        {
            printf("%s: No such file or directory\n", command);
        }
    }

    free(command);
    return 0;
}
