#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * main - Simple UNIX command line interpreter.
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[BUFFER_SIZE];
    char *newline;
    char *args[2] = {NULL, NULL};
    ssize_t bytes_read;
    size_t buffer_len = BUFFER_SIZE;

    while (1)
    {
        /* Display prompt */
        printf("#cisfun$ ");
        fflush(stdout);

        /* Read user input */
        bytes_read = getline(&buffer, &buffer_len, stdin);
        if (bytes_read == -1)
        {
            if (feof(stdin)) /* Handle end of file (Ctrl+D) */
            {
                printf("\n");
                break;
            }
            perror("getline");
            exit(EXIT_FAILURE);
        }

        /* Remove trailing newline */
        newline = strchr(buffer, '\n');
        if (newline)
            *newline = '\0';

        /* Execute command */
        args[0] = buffer;
        if (access(args[0], X_OK) == 0) /* Check if executable exists */
        {
            pid_t pid = fork();
            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            if (pid == 0)
            {
                /* Child process */
                execve(args[0], args, NULL);
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                /* Parent process */
                wait(NULL); /* Wait for the child process to finish */
            }
        }
        else
        {
            /* Executable not found */
            printf("%s: command not found\n", buffer);
        }
    }

    return (0);
}

