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
	pid_t pid;
	int cmd_size, flag = 0, isBuiltin = 0;

	while ((line = _getline(&buffer, &size, stdin)) != -1)
	{
		if (line == 0)
			continue;

		cmd = _strtok(buffer, DELIM, &cmd_size);
		if (cmd[0][0] == '/')
		{
			exe = cmd[0];
			flag = 0;
		}else
		{
			flag = 1;
			exe = _which(cmd[0]);
		}
		isBuiltin = builtinCheck(exe); /*check if cmd is a built-in*/
		if (!isBuiltin && !isDir(buffer) && exe != NULL)
		{
			pid = fork();
			if (pid == 0) /*child process*/
			{
				if (execve(exe, cmd, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			} else
			{
				wait(NULL);
			}
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
 * nonInteractive
 *
 *
 *
 *
void nonInteractive(int argc, char *argv[])
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
	}*/
