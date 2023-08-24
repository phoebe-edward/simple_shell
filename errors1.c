#include "shell.h"
/**
 * _erratoi - error ASCII to int
 * @s: string pointer
 * Return: 0 (no nums), coverted numbers or -1 (error)
 */
int _erratoi(char *s)
{
	int j = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			res  = res * 10;
			res = res + (s[j] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
/**
 * print_error - print error msg
 * @info: pointer to info structure
 * @estr: string for error type
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - print int number (decimal: base 10)
 * @input: int num
 * @fd: file descriptor
 * Return: num of chars printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, counter = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		counter++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			counter++;
		}
		current %= j;
	}
	__putchar('0' + current);
	counter++;
	return (counter);
}
/**
 * convert_number - like itoa (int to ASCII)
 * @num: number
 * @base: base what
 * @flags: args flags
 * Return: converted string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char Buff[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "on123456789ABCDEF";
	ptr = &Buff[49];
	*ptr = '\0';
	do {
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * remove_comments - removes comments
 * @buf: address of the string to be modified
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
	{
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
	}
}
