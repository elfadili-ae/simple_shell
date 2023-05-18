#include "shell.h"

/**
 * main - simple shell
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 */
int main(UNUSED int argc, char *argv[], char *envp[])
{
	data_t data;


	if (isatty(STDIN_FILENO) && argc == 1)
		data.modo = 1;
	else
		data.modo = 0;

	errno = 0;

	/*initialize data*/
	data.progName = argv[0];
	data.argv = argv;
	data.envp = envp;
	data.lineptr = NULL;
	data.cmd = NULL;
	data.cmdCounter = 0;

	interactive(argc, &data);

	return (0);
}
