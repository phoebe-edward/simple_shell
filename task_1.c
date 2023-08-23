#include "shell.h"
/**
 * task_1 - make simple shell with complete path
 * @argv: pointer to pointer to arguments
 * Return: 0
 */
int task_1(char **argv)
{
	char *line = NULL, *args[2] = {NULL, NULL};
	size_t n = 0;
	ssize_t num;
	int status;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "#cisfun$ ", 9);
		num = getline(&line, &n, stdin);
		if (num == -1)
		{
			perror("Error for getline: "), free(line);
			return (1);
		}
		_strcspn(line);
		args[0] = line;
		pid = fork();
		if (pid == -1)
		{
			perror("Error for fork: "), free(line);
			return (1);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror(argv[0]);
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
