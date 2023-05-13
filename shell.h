#ifndef SHELL_H
#define SHELL_H

#define DELIM " "
#define UNUSED __attribute__((unused))

extern char **environ;

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
#include <stdarg.h>

/******modes_functions**********/
void interactive(int argc, char *argv[]);
void nonInteractive(void);

/*******Functions**************/
ssize_t _getline(char **lptr, size_t *n, FILE *strm);
char *_getenv(char *v);
char *_which(char *cmd);

/*******strtok*****************/
char **_strtok(char *str, const char *delim, int *size);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);

/********str_helpers***********/
void _puts(char *s);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
int _strchr2(char *s, char c);

/*******MEMORY_USAGE***********/
void freeSarray(char **Sarray, int size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
