#include "shell.h"

/**
 *
 *
 *
 *
 */
int builtinCheck(char **cmd)
{
	int (*fun)(char**);

	fun = get_builtin(cmd[0]);
	if (fun)
	{
		fun(cmd);
	}
	else
		return (0);

	return (1);
}

/**
 * get_builtin - get the corresponding built-in function to the
 * command entered.
 * @cmd: command
 * Return: function (success) | 0 (failed)
 *
 */
int (*get_builtin(char *cmd))(char **)
{
	int i;
	builtin_t bltin[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL}
	};

	for (i = 0; bltin[i].name != NULL; i++)
	{
		  if (_strncmp(cmd, bltin[i].name, _strlen(bltin[i].name)) == 0)
			  return (bltin[i].f);
	}
	return (0);
}
