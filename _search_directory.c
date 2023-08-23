#include "shell_5.h"
/**
 * _search_directory - searches a certain directory for the command
 * @directory: DIR pointer
 * @command: char pointer
 * @command_len: length of command
 * Return: full_path or null
 */
char *_search_directory(char *one_path, DIR *directory, char *command, unsigned int comm_len)
{
	char *full_path = NULL;
        char *intermediate_path = NULL;
        struct dirent *entry;
        unsigned int j, entry_len = 0;

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
	return (NULL);
}
