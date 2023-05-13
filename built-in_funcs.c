#include "shell.h"

/**
 *
 *
 *
 */
int builtin_exit(char *arg)
{
	char **cmd;
	int size = 0;

	cmd = _strtok(arg, DELIM, &size);

	if (size == 1)
		exit(EXIT_SUCCESS);
	else if (size == 2)
	{
		if (_isDigit(cmd[1]))
			exit(atoi(cmd[1]));
		else
		{
			_puts("exit: numeric argument required\n");
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		if(_isDigit(cmd[1]))
			_puts("exit: too many arguments\n");
		else
		{
			printf("usage: exit [argument]\n"); /* Optional line */
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
/**
 *
 */
int builtin_env(char *arg)
{
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
	return (0);
}
