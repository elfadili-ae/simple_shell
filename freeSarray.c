#include "shell.h"
/**
 *
 *
 *
 */
void freeSarray(char **Sarray)
{
	int i = 0;

	for (; Sarray[i] != NULL; i++)
		free(Sarray[i]);
	free(Sarray);
}
