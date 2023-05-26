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
			code = _atoi(data->cmd[idx + 1]);
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
 * builtin_cd - cd builtin function
 * @data: data holder
 * @idx: command index
 * Return: 1 (success)
 */
int builtin_cd(data_t *data, UNUSED int idx)
{
	char *sweetHome = _getenv("HOME=", data), oldpwd[128] = {'\0'};
	char *prevdir = NULL;
	int status = 0, pos = 5;

	if (data->cmd[1])
	{
		if (_strcmp(data->cmd[1], "-") == 0)
		{
			prevdir = _getenv("OLDPWD=", data);
			if (prevdir != NULL)
				status = setPWD(data, prevdir, 1);
			else
			{
				_setenv(data, "OLDPWD", getcwd(oldpwd, 128));
				_puts(oldpwd + _strchr2(oldpwd, '='), 1);
				_puts("\n", 1);
			}
		}
		else
		{
			status = setPWD(data, data->cmd[1], 0);
		}
	}
	else
	{
		if (sweetHome == NULL)
		{
			pos = 0;
			sweetHome = getcwd(oldpwd, 128);
		}
		status = setPWD(data, sweetHome + pos, 0);
	}

	return (status);
}
/**
 * builtin_env - print the environement variables
 * @data: data holder
 * @idx: command index
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
 * builtin_setenv - set an ennvironement variable
 * @data: data holder
 * @idx: command index
 * Return: 1 (success)
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
 * builtin_unsetenv - unsest an environement varaible
 * @data: data holder
 * @idx: command index
 * Return: 1 (success)
 */
int builtin_unsetenv(data_t *data, int idx)
{
	int i, j;

	if (data->cmd[idx + 1] != NULL)
	{
		for (i = 0; data->envp[i] != 0; i++)
		{
			if (envcmp(data->envp[i], data->cmd[idx + 1]))
			{
				free(data->envp[i]);
				for (j = i + 1; data->envp[j] != NULL; j++)
					data->envp[j - 1] = data->envp[j];
				data->envp[j - 1] = NULL;
				break;
			}
		}
	}
	return (1);
}
