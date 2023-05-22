#include "shell.h"

/**
 * main - simple shell
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 */
int main(int argc, char *argv[], char *envp[])
{
	int i;
	data_t data;

	if (isatty(STDIN_FILENO) && argc == 1)
		data.modo = 1;
	else
		data.modo = 0;

	errno = 0;

	/*initialize data*/
	data.progName = argv[0];
	data.argv = argv;

	/*copy envp*/
	data.envp = malloc(sizeof(char*) * 64);

	for (i = 0; i < 64; i++)
		data.envp[i] = NULL;

	envcpy(data.envp, envp);
	envp = data.envp;
	/** alias **/
	data.alias = malloc(sizeof(char*) * 24);
	for (i = 0; i < 24; i++)
		data.alias[i] = NULL;

	data.lineptr = NULL;
	data.cmd = NULL;
	data.cmdSize = 0;
	data.cmdCounter = 0;
	data.pewd = NULL;

	interactive(argc, &data);

	return (0);
}
