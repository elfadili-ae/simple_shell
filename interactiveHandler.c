#include "shell.h"

/**
 * interactive - simple shell interactive mode
 * @argc: arguments count
 * @argv: arguments vector
 */
void interactive(int argc, char *argv[])
{
	char *buffer = NULL, **cmd;
	size_t size;
	ssize_t line;
	int pid;

	while ((line = _getline(&buffer, &size, stdin)) != -1)
	{
		if (_strcmp(buffer, "exit\n") == 0)
			break;

		cmd = _strtok(buffer, DELIM);

		pid = fork();
		if (pid == 0)
		{
			if (execve(cmd[0], cmd, NULL) == -1)
			{
				_puts(argv[0]);
				_puts(": ");
				_puts(cmd[0]);
				_puts(": not found\n");
			}
			freeSarray(cmd);
			return;
		}
		else
		{
			wait(NULL);
		}
	}

	free(buffer);
	(void)argc;
}
