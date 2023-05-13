#include "shell.h"

/**
 *
 *
 *
 */
int main(__attribute__((unused))int argc, char *argv[]__attribute__((unused)))
{

/*	if (isatty(STDIN_FILENO))*/
	interactive(argc, argv);
	/*else
		printf("non-interactive mode\n");
		nonInteractive(argc, argv);*/

	return (0);
}
