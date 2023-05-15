#include "shell.h"

/**
 * interactive - simple shell interactive mode
 * @ac: arguments count
 * @av: arguments vector
 */
void interactive(UNUSED int ac, data_t *data)
{
	char *exe = NULL;
	size_t size;
	ssize_t line;
	int cmd_size, flag = 0, isBuiltin = 0;

	while ((line = prompt(&data->lineptr, &size, stdin)) != -1)
	{
		data->cmdCounter++;
		if (line == 0)
			continue;

		data->cmd = _strtok(data->lineptr, DELIM, &cmd_size);
		data->cmdSize = cmd_size;
		isBuiltin = builtinCheck(data);
		if (isBuiltin)
			continue;
		else if (data->cmd[0][0] == '/')
		{
			exe = data->cmd[0];
			flag = 0;
		} else
		{
			flag = 1;
			exe = _which(data);
		}
		if (!isBuiltin && !isDir(data->cmd[0]) && exe != NULL)
			processHandler(exe, data);
		else
			Notfound(data);
		if (flag == 1)
		{
			free(data->lineptr);
			data->lineptr = NULL;
			freeSarray(data->cmd, data->cmdSize);
		}
	}
	free(data->lineptr);
}

/**
 * processHandler - fork and handle childe process
 * @exe: name of the executable to run in the child process
 * @cmd: the command buffer
 */
void processHandler(char *exe, data_t *data)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		/*child process*/
		if (execve(exe, data->cmd, data->envp) == -1)
		{
			_puts(data->progName);
			_puts(": ");
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
