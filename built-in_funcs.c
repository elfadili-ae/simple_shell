#include "shell.h"

/**
 *
 *
 *
 */
int builtin_exit(data_t *data)
{

	int size = data->cmdSize, code;

	if (size == 1)
	{
		freeData(data);
		exit(EXIT_SUCCESS);
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
			_puts("exit: numeric argument required\n");
			freeData(data);
			exit(2);
		}
	}
	else
	{
		if(_isDigit(data->cmd[1]))
			_puts("exit: too many arguments\n");
		else
		{
			printf("Usage: exit [argument]\n");
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
	int status;
	int size = data->cmdSize;

	if (size == 1)
		status = chdir("/home");
	else
		status = chdir(data->cmd[1]);

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
int builtin_env(data_t *data)
{
	int i = 0;

	for (; data->envp[i] != NULL; i++)
	{
		_puts(data->envp[i]);
		_puts("\n");
	}
	return (1);
}
