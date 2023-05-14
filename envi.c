#include "shell.h"

/**
 *
 *
 *
 */
char *_getenv(char *var, char *envp[])
{
	int i, len;

	len = _strlen(var);
	for (i = 0; envp[i]; i++)
	{
		if (_strncmp(envp[i], var, len) == 0)
		{
			return (envp[i]);
		}
	}

	return (NULL);
}
