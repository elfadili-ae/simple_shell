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
