#ifndef SHELL_H
#define SHELL_H

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

#define DELIM " \t\n"
#define UNUSED __attribute__((unused))


/*******data_struct***************/
/**
 * data - struct holding program's data
 * @progName: program's name
 * @lineptr: line pointer
 * @cmd: command line tokenized
 * @envp: environment
 */
typedef struct data_t
{
	char *progName;
	char *lineptr;
	char **cmd;
	int cmdSize;
	int cmdCounter;
	char **envp;
} data_t;

/*******built-in_struct************/
/**
 * builtin_t - built-ins name and function
 * @name: name of the built-in
 * @f: the built-in's function
 */
typedef struct builtin_t
{
	char *name;
	int (*f)(data_t*);
} builtin_t;

/******MODE_FUNCTIONS**********/
void interactive(int argc, data_t *data);
void nonInteractive(void);
void processHandler(char *exe, data_t *data);

/*******FUNCTIONS**************/
ssize_t prompt(char **lptr, size_t *n, FILE *strm);
char *_getenv(char *var, data_t *data);
char *_which(data_t *data);
int isDir(char *path);
void Notfound(data_t *data);

/*******BUILT-IN***************/
int builtinCheck(data_t *data);
int (*get_builtin(char *arg))(data_t*);
int builtin_exit(data_t *data);
int builtin_env(data_t *data);
int builtin_cd(data_t *data);

/*********STRTOK***************/
char **_strtok(char *str, const char *delim, int *size);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);
int isDelim(char c, const char *delim);

/********STR_HELPERS***********/
void _puts(char *s);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
int _strchr2(char *s, char c);

/*******MEMORY_USAGE***********/
void freeData(data_t *data);
void freeSarray(char **arr, int size);
char *_memcpy(char *dest, char *src, unsigned int n);

/*******MORE_HELPERS**********/
int _isDigit(char *s);
void print_int(int n);

#endif
