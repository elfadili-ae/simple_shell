#include "shell.h"


/**
 * exeFixer - add the path to the exe if it exists
 *
 *
 */
char *exeFixer(char *cmd, data_t *data)
{
	char *exe;

	if (cmd[0] == '/')
		exe = cmd;
	else
		exe = _which(cmd, data);

	return (exe);
}


/**
 * cmmandsCounter - count the numer of commands
 * @data: data holder
 * Return: number of commands
 */
int commandsCounter(data_t *data)
{
	int i, cmdCount = 1;

	for (i = 0; data->cmd[i + 1] != NULL; i++)
	{
		if (_strcmp(data->cmd[i], "&&") == 0
		    || _strcmp(data->cmd[i], "||") == 0
		    || _strcmp(data->cmd[i], ";") == 0)
			cmdCount++;
	}
	return (cmdCount);
}

/**
 *
 *
 *
 */
int tokCompare(UNUSED char *tok, UNUSED char *ptr, int *sep, int *flag)
{
	if (_strcmp(tok, ";") == 0)
	{
		*sep |= 1;
		return (1);
	}
	else if (_strcmp(tok, "&&") == 0)
	{
		*sep |= 2;
		return (1);
	}
	else if (_strcmp(tok, "||") == 0)
	{
		*sep |= 4;
		return (1);
	}
	(void)flag;
	return (0);
}
