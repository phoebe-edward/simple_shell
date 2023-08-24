#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * execute_command - Execute a command in the shell.
 * @command: The command to execute.
 */
void execute_command(const char *command)
{
	char *args[2] = {NULL, NULL};

	args[0] = (char *)command;

	if (access(args[0], X_OK) == 0)
	{
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
	execve(args[0], args, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
	}
	else
	{
	printf("%s: command not found\n", command);
	}
}

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	size_t buffer_len = BUFFER_SIZE;

	while (1)
	{
	display_prompt();

	bytes_read = getline(&buffer, &buffer_len, stdin);
	if (bytes_read == -1)
	{
	if (feof(stdin))
	{
	printf("\n");
	break;
	}
	perror("getline");
	exit(EXIT_FAILURE);
	}

	char *newline = strchr(buffer, '\n');

	if (newline)
	*newline = '\0';
	execute_command(buffer);
	}

	return (0);
}
