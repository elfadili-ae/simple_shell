#include "shell.h"

/**
 * _getenv - get envioronment variables value
 *
 *
 */
char *_getenv(char *var, data_t *data)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; data->envp[i]; i++)
	{
		if (_strncmp(data->envp[i], var, len) == 0)
		{
			return (data->envp[i]);
		}
	}

	return (NULL);
}

/**
 * envcpy - make a copy of the environement variables
 * @envicopy: environement copy
 * @envp: pointer to environement
 * Return: copy | NULL
 */
char **envcpy(char **envicopy, char **envp)
{
	int i;

	if (envp == NULL)
		return (NULL);

	for (i = 0; envp[i]; i++)
	{
		envicopy[i] = _strdup(envp[i]);
	}

	return (envicopy);
}

/**
 *
 *
 *
 */
int envCount(data_t *data)
{
	int i;

	for (i = 0; data->envp[i]; i++)
		;
	return (i);
}
