#include "shell.h"

/**
 *
 *
 *
 */
int builtin_exit(char **cmd, UNUSED char **envp)
{

	int size = 0, code;

	for (; cmd[size] != NULL; size++)
		;

	if (size == 1)
	{
		freeSarray(cmd, size);
		exit(EXIT_SUCCESS);
	}
	else if (size == 2)
	{
		if (_isDigit(cmd[1]))
		{
			code = atoi(cmd[1]);
			freeSarray(cmd, size);
			exit(code);
		}
		else
		{
			_puts("exit: numeric argument required\n");
			freeSarray(cmd, size);
			exit(2);
		}
	}
	else
	{
		if(_isDigit(cmd[1]))
			_puts("exit: too many arguments\n");
		else
		{
			printf("usage: exit [argument]\n");
			freeSarray(cmd, size);
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
int builtin_cd(char **cmd, UNUSED char **envp)
{
	int status;
	int size = 0;

	for (; cmd[size] != NULL; size++)
		;
	if (!cmd[1])
		status = chdir("/home");
	else
		status = chdir(cmd[1]);

	if (status == -1)
	{
		perror("cd");
	}
	freeSarray(cmd, size);
	return (1);
}

/**
 * builtin_env
 *
 *
 */
int builtin_env(char **cmd, char **envp)
{
	int i = 0, size = 0;

	for (; cmd[size] != NULL; size++)
		;
	for (; envp[i] != NULL; i++)
	{
		_puts(envp[i]);
		_puts("\n");
	}
	freeSarray(cmd, size);
	return (1);
}
