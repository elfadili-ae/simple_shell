#include "shell.h"

/**
 * interactive - simple shell interactive mode
 * @ac: arguments count
 * @av: arguments vector
 */
void interactive(UNUSED int ac, char *av[], char *envp[])
{
	char *buffer = NULL, **cmd = NULL, *exe = NULL;
	size_t size;
	ssize_t line;
	int cmd_size, flag = 0, isBuiltin = 0, Ecount = 0;

	while ((line = _getline(&buffer, &size, stdin)) != -1)
	{
		Ecount++;
		if (line == 0)
			continue;

		cmd = _strtok(buffer, DELIM, &cmd_size);
		isBuiltin = builtinCheck(cmd, envp); /*check if cmd is a built-in*/
		if (isBuiltin)
			continue;
		else if (cmd[0][0] == '/')
		{
			exe = cmd[0];
			flag = 0;
		} else
		{
			flag = 1;
			exe = _which(cmd[0], envp);
		}
		if (!isBuiltin && !isDir(buffer) && exe != NULL)
		{
			processHandler(exe, cmd, envp);
		} else
			Notfound(av[0], cmd[0], Ecount);
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
void processHandler(char *exe, char **cmd, char *envp[])
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		/*child process*/
		if (execve(exe, cmd, envp) == -1)
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
