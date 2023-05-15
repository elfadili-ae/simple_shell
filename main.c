#include "shell.h"

/**
 * main - simple shell
 *
 *
 */
int main(UNUSED int argc, char *argv[], char *envp[])
{
	data_t data;

	/*initialize data*/
	data.progName = argv[0];
	data.envp = envp;

	interactive(argc, &data);

	return (0);
}
