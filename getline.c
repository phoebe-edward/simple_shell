#include "main.h"
#define BUFFER_SIZE 1024
/**
 * read_input - Read input from standard input.
 *
 * @buffer: Buffer to store read input
 * @size: size of the buffer
 *
 * Return: Number of bytes read or -1 on error.
 */
static ssize_t read_input(char *buffer, size_t size)
{
	return (read(STDIN_FILENO, buffer, size));
}
/**
 * allocate_line_buffer -  Allocate memory for a line buffer.
 *
 * @size: Size of the buffer to allocate.
 *
 * Return: Pointer to the allocated buffer.
 */
static char *allocate_line_buffer(size_t size)
{
	char *line = malloc(size);

	if (line ==  NULL)
	{
	perror("malloc");
	exit("EXIT_FAILURE");
	}
	return (line);
}
/**
 * custom_getline - Read input from the user using a custom buffer.
 *
 * Return: Pointer to the read line or NULL on EOF or error.
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index = 0;
	static size_t buffer_size = 0;

	char *line = NULL;

	size_t line_length = 0;

	while (1)
	{
	if (buffer_index >= buffer_size)
       	{
	buffer_size = read_input(buffer, BUFFER_SIZE);
	buffer_index = 0;

	if (buffer_size <= 0)
	{
	if (line_length ==  0)
	return (NULL);
	else
	{
	line = allocate_line_buffer(line_length + 1);
	line[line_length = '\0';
	return (line);
	}
	}
	}

	}
}
