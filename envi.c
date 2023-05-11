#include "shell.h"

/**
 *
 *
 *
 */
char **_getenv(char *v)
{
	int i, len;

	len = _strlen(v);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(v, environ[i], len) == 0)
			return (&environ[i]);
	}

	return (NULL);
}
