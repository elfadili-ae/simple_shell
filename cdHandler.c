#include "shell.h"
/**
 * _setenv - set or modify an environement variable
 * @name: variable name
 * @value: value of the variable
 * @data: data holder
 */
void _setenv(char *name, char *value, data_t *data)
{
	int i, len;
	char flag = 0;

	if (name != NULL && value != NULL)
	{
		for (i = 0; data->envp[i] != 0; i++)
		{
			if (envcmp(data->envp[i], name))
			{
				free(data->envp[i]);
				flag = 1;
				break;
			}
		}
		len = _strlen(name) + _strlen(value) + 1;
		data->envp[i] = malloc(len + 1);
		if (data->envp[i] == NULL)
		{
			errno = ENOMEM;
			perror("Error");
			exit(128);
		}
		_strcpy(data->envp[i], name);
		_strcat(data->envp[i], "=");
		_strcat(data->envp[i], value);
		data->envp[i][len] = '\0';

		if (!flag)
			data->envp[i + 1] = NULL;
	}
}
