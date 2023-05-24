#include "shell.h"

/**
 * _getenv - get envioronment variables value
 * @var: varaible
 * @data: data holder
 * Return: string
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
 * envcmp - check if the variable exists
 * @env: pointer to the environement variable
 * @var: variable to check
 * Return: variable | NULL
 */
char *envcmp(char *env, char *var)
{
	int len;

	if (env == NULL || var == NULL)
		return (NULL);

	len = _strlen(var);

	if (_strncmp(var, env, len) == 0 && env[len] == '=')
	{
		return (env);
	}

	return (NULL);
}

/**
 * envCount - environement Counter
 * @data: data holder
 * Return: integer
 */
int envCount(data_t *data)
{
	int i;

	for (i = 0; data->envp[i]; i++)
		;
	return (i);
}
