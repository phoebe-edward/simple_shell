#include "shell_5.h"
/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: source string, will be concatenated after the dest
 * Return: the pointer to new string (res)
 */

char *_strcat(char *dest, char *src)
{
	int i, len_dest, j, k, len_src, l;
	char *res;

	for (i = 0; dest[i] != '\0'; i++)
		;
	len_dest = i;
	/*printf("length of dest = %d\n", len_dest);*/
	for (k = 0; src[k] != '\0'; k++)
		;
	len_src = k;
	/*printf("length of src = %d\n", len_src);*/
	res = malloc(sizeof(char) * (len_dest + len_src) + 1);
	if (res == NULL)
		return (NULL);
	for (j = 0; dest[j] != '\0'; j++)
	{
		res[j] = dest[j];
	}
	for (l = 0; src[l] != '\0'; l++)
	{
		res[j + l] = src[l];
	}
	res[j + l] = '\0';
	return (res);
}
