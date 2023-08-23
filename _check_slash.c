#include "shell_5.h"
/**
 * _check_slash - check if this ia a complete path or not
 * @command: char pointer to command string
 * Return: 0 if complete path, 1 if not, -1 if NULL command
 */
int _check_slash(char *command)
{
	int i;

	if (command == NULL)
		return (-1);
	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
			return (0);
	}
	return (1);
}
