#include "shell.h"
/**
 * _strcspn - method
 * @str: char pointer
 * Return: char pointer
 */
char *_strcspn(char *str)
{
	int i = 0;

	while (str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		str[i] = '\0';
	return (str);
}
