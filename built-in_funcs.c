#include "shell.h"

/**
 * builtin_exit - exit the program
 * @data: data holder
 * Return: 1 | exit (errno)
 */
int builtin_exit(data_t *data)
{

	int size = data->cmdSize, code;

	if (size == 1)
	{
		freeData(data);
		exit(errno);
	}
	else if (size == 2)
	{
		if (_isDigit(data->cmd[1]))
		{
			code = atoi(data->cmd[1]);
			freeData(data);
			exit(code);
		}
		else
		{
			_puts(data->progName, 2);
			_puts(": ", 2);
			print_int(data->cmdCounter, 2);
			_puts(": ", 2);
			_puts(data->cmd[0], 2);
			_puts(": Illegal number: ", 2);
			_puts(data->cmd[1], 2);
			_puts("\n", 2);
			freeData(data);
			exit(2);
		}
	}
	return (1);
}
/**
 * builtin_cd
 *
 *
 */
int builtin_cd(data_t *data)
{
	char *sweetHome = _getenv("HOME=", data);
	char *pwd = _getenv("PWD=", data);
	int status, size = data->cmdSize;

	if (size == 1)
	{
		status = chdir(sweetHome);
	}
	else if (size == 2)
	{
		if (strcmp(data->cmd[1], "-") == 0)
		{
			_puts(pwd, 1);
			_puts(" go to pwd\n", 1);
		}
		else
			status = chdir(data->cmd[1]);
	}

	if (status == -1)
	{
		_puts("cd: failed\n", 2);
		exit(128);

	}
	return (1);
}

/**
 * builtin_env - print the environement variables
 * @data: data holder
 * Return: 1 (called)
 */
int builtin_env(data_t *data)
{
	int i = 0;

	for (; data->envp[i] != NULL; i++)
	{
		_puts(data->envp[i], 1);
		_puts("\n", 1);
	}
	return (1);
}
