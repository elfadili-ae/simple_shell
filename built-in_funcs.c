#include "shell.h"

/**
 *
 *
 *
 */
void builtin_exit(char *arg)
{
	char **cmd;
	int size;

	cmd = _strtok(arg, DELIM, &size);


	if (size == 2)
	{
		if (_isDigit(cmd[1]))
		{
			exit(cmd[1]));
		else
			printf("%s: numeric argument required\n",cmd[1]);
	}
	exit(EXIT_SUCCESS);
}
