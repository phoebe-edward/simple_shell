#include "main.h"
/**
 * _strncmp - string compare n characters
 * @s1: first string
 * @s2: second string
 * @n: number of characters to be compared
 * Return: negative or positive or zero if they are equivalent
*/
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		if (s2[i] - s1[i] != 0)
			return (s2[i] - s1[i]);
		i++;
	}
	return (0);
}
