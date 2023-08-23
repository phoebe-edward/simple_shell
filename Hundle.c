#include "main.h"

int compareStrings(const char *str1, const char *str2);

void executeCommand(char *cmd, char *args[]);

void token(char *command);

/* Documentation for compareStrings() */

/**
 * compareStrings - Compare two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Returns:
 *  1 if the strings are equal, otherwise 0.
 */
int compareStrings(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
	str1++;
	str2++;
	}
	return (*str1 == '\0' && *str2 == '\0');
}
/**
 * executeCommand - Execute a command with given arguments.
 *
 * @cmd: The command to execute.
 * @args: An array of arguments for the command.
 */
void executeCommand(char *cmd, char *args[])
{
	pid_t pid = fork();

	if (pid < 0)
	{
	char error_msg[] = "Forking failed\n";

	write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
	return;
	}
	else if (pid == 0)
	{
	if (access(cmd, X_OK) == 0)
	{
	execve(cmd, args, NULL);
	char error_msg[] = "Error executing command\n";

	write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
	_exit(EXIT_FAILURE);
	}
	else if (compareStrings(cmd, "ls"))
	{
	char *ls_args[] = {"/bin/ls", "-la", NULL};

	execve(ls_args[0], ls_args, NULL);
	char error_msg[] = "Error executing command\n";

	write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
	_exit(EXIT_FAILURE);
	}
	else
	{
	char error_msg[] = "No such file or directory\n";

	write(STDOUT_FILENO, cmd, sizeof(cmd));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
	_exit(EXIT_FAILURE);
	}
	}
	else
	{
	waitpid(pid, NULL, 0);
	}
}
/**
 * token - Tokenize and execute a command.
 *
 * @command: The input command to tokenize and execute.
 */
void token(char *command)
{
	char *args[MAX_ARGS];
	char *token = strtok(command, " ");
	int arg_count = 0;

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
	args[arg_count] = token;
	arg_count++;
	token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (arg_count > 0)
	{
	executeCommand(args[0], args);
	}
}
