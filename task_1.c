#include "shell.h"

/**
 * executeCommand - Executes given command, managing child process,
 * permissions, and errors.
 * @command: Command to execute
 */
void executeCommand(const char *command)
{
<<<<<<< HEAD
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
int prompt(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;
=======
	size_t n = 255;
	char *line = malloc(sizeof(char) * n), *args[2] = {NULL, NULL};
	ssize_t num;
	int status = 0;
>>>>>>> 061d962d6608d6d42265c450f95b61d2c905eb8d

	if (line == NULL)
		return (1);
	while (1)
	{
<<<<<<< HEAD
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
=======
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "#cisfun$ ", 9);
		num =  read(STDIN_FILENO, line, n);
		if (num == -1)
		{
			perror("Error for getline: "), free(line);
			return (1);
		}
		if (num == 0)
			break;
		args[0] = _strcspn(line);
		if (_fork_fcn(line, args, status, argv) == 1)
		{
			free(line);
			return (1);
		}
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
			perror(argv[0]), free(line);
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
>>>>>>> 061d962d6608d6d42265c450f95b61d2c905eb8d
	return (0);
}
