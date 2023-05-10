#ifndef SHELL_H
#define SHELL_H

/********Libraries*********/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

/*******Functions**********/
void _getline(char **restrict lptr, size_t *restrict n, FILE *restrict strm);

/********helpers***********/
void _puts(char *s);
int _strlen(char *s, int j);


#endif
