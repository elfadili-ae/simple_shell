#include "shell.h"

/**
 *
 *
 *
 *
 */
int builtinCheck(char *cmd)
{
	int (*fun)(char*);

	fun = get_builtin(cmd);
	if (fun)
	{
		fun(cmd);
	}

	return (0);
}

/**
 * get_builtin - get the corresponding built-in function to the
 * command entered.
 * @cmd: command
 * Return: function (success) | 0 (failed)
 *
 */
int (*get_builtin(char *cmd))(char *)
{
	int i;
	builtin_t builtin[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL}
	};

		for (i = 0; builtin[i].name != NULL; i++)
	{
		if (_strncmp(builtin[i].name, cmd, _strlen(cmd)))
			return (builtin[i].f);
	}
	return (0);
}
