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
	int pid;

	while ((line = _getline(&buffer, &size, stdin)) != -1)
	{
		if (line == 0)
			continue;
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			break;
		}

		cmd = _strtok(buffer, DELIM);
		exe = _which(cmd[0]);
		if (exe != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(exe, cmd, NULL) == -1)
				{
					perror("Error");
				}
				free(exe);
				return;
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			_puts("Error: ");
			_puts(cmd[0]);
			_puts(": Not found\n");
		}
		free(buffer);
		buffer = NULL;
		freeSarray(cmd);
	}
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
