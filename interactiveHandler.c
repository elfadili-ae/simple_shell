#include "shell.h"

/**
 * interactive - simple shell interactive mode
 * @ac: arguments count
 * @av: arguments vector
 */
void interactive(int ac, data_t *data)
{
	int size, line, fd;

	if (!data->modo && ac == 2)
		fd = openFile(data);

	while ((line = prompt(data, &size, fd)) != -1 || data->lineptr)
	{
		data->cmdCounter++;
		if (line == 0)
			continue;

		commentHandler(data);
		data->lineptr = opSep(data);
		data->cmd = _strtok(data->lineptr, DELIM, &data->cmdSize);

		if (data->cmdSize > 0)
		{
			processHandler(data);
			freeData(data);
		}
	}
	if (!data->modo && ac == 2)
		closeFile(data, fd);
	free(data->lineptr);
}

/**
 * processHandler - fork and handle parent/child process
 * also andle operands && and ||
 * @exe: name of the executable to run in the child process
 * @cmd: the command buffer
 */
void processHandler(data_t *data)
{
	int stat = 0, i, j, k = 0, f = 0, Count, isBI = 0, pos = 0;
	int cmp2, cmp = 0, sep = 0;
	char *exe = NULL, *ptr[64];

	Count = commandsCounter(data);
	for (i = 0; i < Count; i++)
	{
		for (j = 0; data->cmd[pos + j] != NULL; j++)
		{
			if (i < Count - 1)
			{
				cmp2 = tokChecker(data->cmd[pos + j]);
				if (cmp2 != 0)
					break;
			} ptr[j] = data->cmd[pos + j];
		} ptr[j] = NULL;

		if (i == 0 || (stat == 0 && cmp == 0) || ((sep  & 2) && stat == 0)
		     || ((sep & 4) && stat != 0) || (sep & 1))
		{
			isBI = builtinCheck(data, ptr[0]);
			if (isBI)
				continue;
			else
			{
				exe = exeFixer(ptr[0], data);
				if (!isBI && !isDir(ptr[0]) && exe != NULL)
					forking(data, ptr, exe, &stat);
				else
					Notfound(data);
			}
		}
		for (sep = 0; i < Count - 1 && data->cmd[pos + k] != NULL; k++)
		{
			cmp = tokCompare(data->cmd[pos + k], &sep, &f);
			if (cmp != 0)
				break;
		}
		pos += j + 1;
	}
}

/**
 * forking - make a child process for the command to execute
 * @data: data holder
 * @exe: the path to the exe
 * Return: the status of the execution
 */
void forking(data_t *data, char **cmd, char *exe, int *stat)
{
	pid_t pid;

	pid = fork();
	if (pid == 0) /*　子ども */
	{
		*stat = execve(exe, cmd, data->envp);
		if (*stat == -1)
			perror(exe), exit(EXIT_FAILURE);
	}
	else /* 母 */
	{
		wait(stat);
		if (WIFEXITED(*stat))
			errno = WEXITSTATUS(*stat);

		if (data->flag)
			free(exe);
		exe = NULL;
	}
}
