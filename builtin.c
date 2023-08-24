#include "shell.h"
/**
 * _myexit - exit the shell
 * @info: structure pointer for information
 * Return: exit status
 */
int _myexit(info_t *info)
{
	int exitch;

	if (info->argv[1])
	{
		exitch = _erratoi(info->argv[1]);
		if (exitch == -1)
		{
			info->status = 2;
			print_error(info, "Illegal Num: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - change directory
 * @info: structure pointer for information
 * Return: 0
 */
int _mycd(info_t *info)
{
	char *s, *Dir, Buff[1024];
	int chdir_rt;

	s = getcwd(Buff, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure msg here<<\n");
	if (!info->argv[1])
	{
		Dir = _getenv(info, "HOME=");
		if (!Dir)
			chdir_rt = chdir((Dir = _getenv(info, "PWD=")) ? Dir : "/");
		else
			chdir_rt = chdir(Dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_rt = chdir((Dir = _getenv(info, "OLDPWD=")) ? Dir : "/");
	}
	else
		chdir_rt = chdir(info->argv[1]);
	if (chdir_rt == -1)
	{
		print_error(info, "can not cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(Buff, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes the directory of the process
 * @info: pointer to info structure
 * Return: 0
 */
int _myhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call. Function not yet done\n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
