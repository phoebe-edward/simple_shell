#include "shell_5.h"
/**
 * _strdup - duplicate string input
 * @str: char pointer input
 * Return: char pointer for duplicated string
 */
char *_strdup(char *str)
{
	char *duplicate = NULL;
	unsigned int str_len = 0, i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	str_len = i;
	duplicate = malloc(sizeof(char) * str_len + 1);
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		duplicate[i] = str[i];
	}
	duplicate[i] = '\0';
	return (duplicate);
}
