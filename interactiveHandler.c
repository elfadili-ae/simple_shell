#include "shell.h"

/**
 * interactive - simple shell interactive mode
 * @ac: arguments count
 * @data: data holder
 */
void interactive(int ac, data_t *data)
{
	int size = 0, line = 0, fd = 0;

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
			specialVarHandler(data);
			processHandler(data);
			freeSarray(data->cmd, data->cmdSize);
			data->cmd = NULL;
			free(data->lineptr);
			data->lineptr = NULL;
		}
	}
	if (!data->modo && ac == 2)
		closeFile(data, fd);
	freeData(data);
}

/**
 * processHandler - fork and handle parent/child process
 * also andle operands && and ||
 * @data: data holder
 */
void processHandler(data_t *data)
{
	int stat = 0, i, j, k = 0, f = 0, Count = commandsCounter(data);
	int cmp2 = 0, cmp = 0, sep = 0, Cpos = 0, isBI = 0, pos = 0, m;
	char *exe = NULL, *ptr[64];

	for (i = 0; i < Count; i++)
	{
		j = processHelper(data, ptr, &i, &pos, &Count, &cmp2);
		if (i == 0 || (stat == 0 && cmp == 0) || ((sep  & 2) && stat == 0)
		    || ((sep & 4) && stat != 0) || (sep & 1))
		{
			Cpos = cmp2 == 0 ? 0 : 1;
			ptr[0] = aliasHandler(data, pos);
			if (i == Count - 1)
			{
				for (m = 0; ptr[m] != NULL; m++)
					;
				if (_strcmp(ptr[m - 1], ";") == 0)
					ptr[m - 1] = NULL;
			}
			isBI = builtinCheck(data, ptr[0], i + Cpos);
			if (isBI)
				continue;
			exe = exeFixer(ptr[0], data);
			if (!isBI && !isDir(ptr[0]) && exe != NULL)
				forking(data, ptr, exe, &stat);
			else
				Notfound(data);
		}
		for (sep = 0; i < Count - 1 && data->cmd[pos + k] != NULL; k++)
		{
			cmp = tokCompare(data->cmd[pos + k], &sep, &f);
			if (cmp != 0)
			{
				k--;
				break;
			}
		} pos += j + 1;
	}
}

/**
 * processHelper - check for separators and operators
 * @data: data holder
 * @ptr: pointer to first argument in the command
 * @i: number of commands index
 * @pos: position of the command in the array of commands
 * @c: numberof commands
 * @cmp2: the number of the sep/operator
 * Return: int
 */
int processHelper(data_t *data, char **ptr, int *i, int *pos,
		  int *c, int *cmp2)
{
	int j;

	for (j = 0; data->cmd[(*pos) + j] != NULL; j++)
	{
		if ((*i) < (*c) - 1)
		{
			*cmp2 = tokChecker(data->cmd[(*pos) + j]);
			if ((*cmp2) != 0)
				break;
		}
		ptr[j] = data->cmd[(*pos) + j];
	}
	ptr[j] = NULL;
	return (j);
}

/**
 * forking - make a child process for the command to execute
 * @data: data holder
 * @cmd: command line
 * @exe: the path to the exe
 * @stat: status
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
		{
			perror(exe);
			exit(EXIT_FAILURE);
		}
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
