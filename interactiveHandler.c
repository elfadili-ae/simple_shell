#include "shell.h"

/**
 * interactive - simple shell interactive mode
 * @ac: arguments count
 * @av: arguments vector
 */
void interactive(UNUSED int ac, UNUSED char *av[])
{
	char *buffer = NULL, **cmd = NULL, *exe = NULL;
	size_t size;
	ssize_t line;
	int cmd_size, flag = 0, isBuiltin = 0;

	while ((line = _getline(&buffer, &size, stdin)) != -1)
	{
		if (line == 0)
			continue;

		cmd = _strtok(buffer, DELIM, &cmd_size);
		isBuiltin = builtinCheck(cmd); /*check if cmd is a built-in*/
		if (isBuiltin)
			continue;
		else if (cmd[0][0] == '/')
		{
			exe = cmd[0];
			flag = 0;
		} else
		{
			flag = 1;
			exe = _which(cmd[0]);
		}
		if (!isBuiltin && !isDir(buffer) && exe != NULL)
		{
			processHandler(exe, cmd);
		} else
		{
			_puts("Error: ");
			_puts(cmd[0]);
			_puts(": Not found\n");
		}
		if (flag == 1)
			free(exe);
		free(buffer);
		buffer = NULL;
		freeSarray(cmd, cmd_size);
	}
	free(buffer);
}

/**
 * processHandler - fork and handle childe process
 * @exe: name of the executable to run in the child process
 * @cmd: the command buffer
 */
void processHandler(char *exe, char **cmd)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		/*child process*/
		if (execve(exe, cmd, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*parent process*/
		wait(NULL);
	}

}
