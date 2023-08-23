#include "shell_5.h"
/**
 * _search_PATH - search for command in all PATH environment variables
 * @command: char pointer for command
 * Return: pointer for full command name (with path) or NULL if not found
 */
char *_search_PATH(char *command)
{
	char *path_values = NULL, *one_path = NULL, *full_path = NULL;
	char *intermediate_path = NULL, *path_values_dup = NULL;
	DIR *directory;
	struct dirent *entry;
	unsigned int i, comm_len = 0, j, entry_len = 0;

	if (command == NULL)
		return (NULL);
	path_values = _getenv("PATH");
	if (path_values == NULL)
	{
		printf("path envireonment variable was not found!\n");
		return (NULL);
	}
	path_values_dup = _strdup(path_values);
	for (i = 0; command[i] != '\0'; i++)
		;
	comm_len = i;
	one_path = strtok(path_values_dup, ":");
	while (one_path != NULL)
	{
		directory = opendir(one_path);
		if (directory == NULL)
		{
			perror("Error opening the directory: ");
			return (NULL);
		}
		entry = readdir(directory);
		while (entry != NULL)
		{
			if (_strncmp(command, entry->d_name, comm_len) == 0)
			{
				for (j = 0; entry->d_name[j] != '\0'; j++)
					;
				entry_len = j;
				if (comm_len == entry_len && comm_len != 0 && entry_len != 0)
				{
					intermediate_path = _strcat(one_path, "/");
					full_path = _strcat(intermediate_path, command);
					if (closedir(directory) == -1)
					{
						perror("Error closing directory: ");
						return (NULL);
					}
					return (full_path);
				}
			}
			entry = readdir(directory);
		}
		if (closedir(directory) == -1)
		{
			perror("Error closing directory: ");
			return (NULL);
		}
		one_path = strtok(NULL, ":");
	}
	return (NULL);
}
