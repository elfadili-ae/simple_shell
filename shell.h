#ifndef SHELL_H
#define SHELL_H

#define DELIM " "

/********Libraries***************/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/******modes_functions**********/
void interactive(int argc, char *argv[]);
void nonInteractive(void);

/*******Functions**************/
ssize_t _getline(char **lptr, size_t *n, FILE *strm);

/*******strtok*****************/
char **_strtok(char *str, const char *delim);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);

/********str_helpers***********/
void _puts(char *s);
int _strlen(char *s, int j);
int _strcmp(char *s1, char *s2);

/*******MEMORY_USAGE***********/
void freeSarray(char **Sarray);

#endif
