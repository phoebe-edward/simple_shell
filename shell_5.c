#include "shell.h"
/**
 * main - entry point (task 1, 3, 4 and 5)
 * @argc: number of args
 * @argv: arguments
 * @env: environment lines (strings)
 * Return: (0)
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL, *args[2] = {NULL, NULL}, *str = NULL, *full_path = NULL;
	size_t n = 0;
	ssize_t num;
	int status, slash;
	pid_t pid;
	unsigned int i, j, line_len;

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
		if (line == NULL)
			printf("HERE LINE IS NULL!!!!!!!!!!!!!\n");
		_strcspn(line);
		if (_strncmp(line, "exit", 4) == 0)
			return (0);
		if (_strncmp(line, "env", 3) == 0)
		{
			for (i = 0; env[i] != NULL; i++)
			{
				for (j = 0; env[i][j] != '\0'; j++)
					;
				str = _strcat(env[i], "\n");
				line_len = j + 1;
				write(STDIN_FILENO, str, line_len);
			}
			free(str);
			str = NULL;
			free(line);
			line = NULL;
			continue;
		}
		printf("before checking slash, line is: %s\n", line);
		slash = _check_slash(line);
		if (slash == -1)
		{
			perror("Error for check slash: "), free(line);
			return (1);
		}
		if (slash == 1)
		{
			printf("slash = 1, line: %s\n", line);
			full_path = _search_PATH(line);
			if (full_path == NULL)
			{
				printf("%s: No such file or directory\n", argv[0]);
				continue;
			}
			args[0] = full_path;
		}
		if (slash == 0)
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
	free(full_path);
	(void)argc;
	return (0);
}
