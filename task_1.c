#include "shell.h"
/**
 * task_1 - make simple shell with complete path
 * @argv: pointer to pointer to arguments
 * Return: 0
 */
int task_1(char **argv)
{
	size_t n = 255;
	char *line = malloc(sizeof(char) * n), *args[2] = {NULL, NULL};
	ssize_t num;
	int status = 0;

	if (line == NULL)
		return (1);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "#cisfun$ ", 9);
		num =  read(STDIN_FILENO, line, n);
		if (num == -1)
		{
			perror("Error for getline: "), free(line);
			return (1);
		}
		args[0] = _strcspn(line);
		if (_fork_fcn(line, args, status, argv) == 1)
			return (1);
		if (!isatty(STDIN_FILENO))
			break;
	}
	free(line);
	return (0);
}
/**
 * _fork_fcn - child and parent functions
 * @line: line to execute
 * @args: arguments for execve
 * @status: integer
 * @argv: char pointer to pointer
 * Return: 1
 */
int _fork_fcn(char *line, char **args, int status, char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error for fork: "), free(line);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(argv[0]);
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
