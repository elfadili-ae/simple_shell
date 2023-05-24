#include "shell.h"
/**
 *
 *
 *
 */
void _setenv(char *name, char *value, data_t *data)
{
	int i = 0, numEnvp = 0;
	char **newEnvp;
	char *env;

	for (; data->envp[i] != NULL; i++)
	{
		if (envcmp(data->envp[i], name))
		{
			char *env = malloc(_strlen(name) + _strlen(value) + 2);
			sprintf(env, "%s=%s", name, value);
			free(data->envp[i]);
			data->envp[i] = env;
			return;
		}
	}
	while (data->envp[numEnvp] != NULL)
		numEnvp++;

	newEnvp = realloc(data->envp, sizeof(char*) * (numEnvp + 2));
	if (newEnvp == NULL)
	{
		perror("Error");
		exit(1);
	}

	env = malloc(_strlen(name) + _strlen(value) + 2);
	sprintf(env, "%s=%s", name, value);

	newEnvp[numEnvp] = env;
	newEnvp[numEnvp + 1] = NULL;

	data->envp = newEnvp;
}
