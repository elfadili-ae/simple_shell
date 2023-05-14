#include "shell.h"

/**
 *
 *
 *
 */
int builtin_exit(char **cmd)
{

	int size = 0;

	for (; cmd[size] != NULL; size++)
		;

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
			printf("usage: exit [argument]\n");
			exit(EXIT_SUCCESS);
		}
	}
	return (1);
}
/**
 * builtin_cd
 *
 *
 */
int builtin_cd(char **cmd)
{
	int status;

	if (!cmd[1])
		status = chdir("/home");
	else
		status = chdir(cmd[1]);

	if (status == -1)
	{
		perror("cd");
	}
	return (1);
}

/**
 * builtin_env
 *
 *
 */
int builtin_env(UNUSED char **arg)
{
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
	return (1);
}
