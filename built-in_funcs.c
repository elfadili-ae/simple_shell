#include "shell.h"

int builtin_exit(data_t *data, int idx);
int builtin_cd(data_t *data, int idx);
int builtin_env(data_t *data, int idx);

/**
 * builtin_exit - exit the program
 * @data: data holder
 * @idx: command index
 * Return: 1 | exit (errno)
 */
int builtin_exit(data_t *data, int idx)
{

	int code = 0;

	if (data->cmd[idx + 1] != NULL)
	{
		if (_isDigit(data->cmd[idx + 1]))
		{
			code = atoi(data->cmd[idx + 1]);
			freeData(data);
			exit(code);
		}
		else
		{
			_puts(data->progName, 2);
			_puts(": ", 2);
			print_int(data->cmdCounter, 2);
			_puts(": ", 2);
			_puts(data->cmd[idx], 2);
			_puts(": Illegal number: ", 2);
			_puts(data->cmd[idx + 1], 2);
			_puts("\n", 2);
			freeData(data);
			exit(2);
		}
	}
	freeData(data);
	exit(errno);
	return (1);
}
/**
 * builtin_cd
 *
 *
 */
int builtin_cd(data_t *data, UNUSED int idx)
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
int builtin_env(data_t *data, UNUSED int idx)
{
	int i = 0;

	for (; data->envp[i]; i++)
	{
		_puts(data->envp[i], 1);
		_puts("\n", 1);
	}
	return (1);
}

/**
 *
 *
 *
 */
int builtin_setenv(data_t *data, int idx)
{
	int i, len;
	char flag = 0;

	if (data->cmd[idx + 1] != NULL && data->cmd[idx + 2] != NULL)
	{
		for (i = 0; data->envp[i] != 0; i++)
		{
			if (envcmp(data->envp[i], data->cmd[idx + 1]))
			{
				free(data->envp[i]);
				flag = 1;
				break;
			}
		}
		len = _strlen(data->cmd[idx + 1]) + _strlen(data->cmd[idx + 2]) + 1;
		data->envp[i] = malloc(len + 1);
		if (data->envp[i] == NULL)
		{
			errno = ENOMEM;
			perror("Error");
			return (1);
		}
		_strcpy(data->envp[i], data->cmd[idx + 1]);
		_strcat(data->envp[i], "=");
		_strcat(data->envp[i], data->cmd[idx + 2]);
		data->envp[i][len] = '\0';

		if (!flag)
			data->envp[i + 1] = NULL;
	}
	return (1);
}

/**
 * builtin_aliases - handle the alias command
 * @data: data holder
 * @idx: command index
 * Return: 1
 */
int builtin_aliases(data_t *data, int idx)
{
	int i = 0, flag = 0;

	if (data->cmd[idx + 1] == NULL)
		printAliases(data, NULL);
	else
	{
		while (data->cmd[idx + 1 + i])
		{
			if (_strchr2(data->cmd[idx + 1 + i], '='))
			{
				addAlias(data, data->cmd[idx + 1 + i]);
				flag = 1;
			}
			else
				flag = printAliases(data, data->cmd[idx + 1 + i]);

			if (!flag)
			{
				_puts("alias: ", 2);
				_puts(data->cmd[idx + 1 + i], 2);
				_puts(" not found\n", 2);
				errno = 127;
			}
			i++;
		}
	}

	return (1);
}
