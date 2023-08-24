#include "shell.h"
/**
 * _myenv - current environment printing
 * @info: structure pointer for info
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - get the values of an environment variable
 * @info: structure pointer
 * @name: environment variable name
 * Return: values of env variable
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - sets an environment variable
 * @info: structure pointer
 * Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect num of args\n");
		return (1);
	}
	if (_setenv(info, info->srgv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - unsets an environment variable
 * @info: pointer to info structure
 * Return: 0
 */

int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Few args\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);
	return (0);
}
/**
 * populate_env_list - populate environment linked list
 * @info: structure pointer
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
