#include "shell_5.h"
/**
 * _getenv - get environment variable value or NULL if not found
 * @name: name of variable
 * Return: pointer to the value of variable or NULL
 */
char *_getenv(char *name)
{
	unsigned int name_len = 0;
	unsigned int i;

	if (name == NULL)
		return (NULL);
	for (i = 0; name[i] != '\0'; i++)
		;
	name_len = i;
	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (&(environ[i][name_len + 1]));
		i++;
	}
	return (NULL);
}
