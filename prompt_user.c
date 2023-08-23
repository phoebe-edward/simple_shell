#include "shell.h"
/**
 * executeCommand - Executes given command, managing child process,
 * permissions, and errors.
 * @command: Command to execute
 */
void executeCommand(const char *command)
{
        if (access(command, X_OK) == 0)
        {
        pid_t pid = fork();

        if (pid < 0)
        {
        perror("Forking failed");
        return;
        }
        else if (pid == 0)
        {
        char *args[] = {(char *)command, NULL};

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

/**
 * prompt - Displays a prompt and executes entered commands.
 * Return: Always 0
 */
int prompt_user(void)
{
        char *command = NULL;
        size_t len = 0;
        ssize_t read;

        while (1)
        {
        if (isatty(STDIN_FILENO))
        printf("#cisfun$ ");
        read = getline(&command, &len, stdin);

        if (read == -1)
        {
        printf("\n");
        break;/* EOF (Ctrl+D)*/
        }
        if (read > 0 && command[read - 1] == '\n')
        {
        command[read - 1] = '\0';
        }
        executeCommand(command);
        }
        free(command);
        return (0);
}
