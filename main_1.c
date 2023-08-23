#include "shell.h"
/**
 * main - entry point (task 1, 3, 4 and 5)
 * @argc: number of args
 * @argv: arguments
 * Return: (0)
 */
int main(int argc, char **argv)
{
	int val;

	val = task_1(argv);
	(void)argc;
	return (val);
}
