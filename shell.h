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
#include <fcntl.h>

/***********defines***************/
#define BUFFSIZE 128
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
	char **argv;
	char *lineptr;
	char **cmd;
	int cmdSize;
	int cmdCounter;
	char **envp;
	int flag;
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
void processHandler(data_t *data);
void forking(data_t *data, char **cmd, char *exe, int *stat);

/*******FUNCTIONS**************/
int prompt(data_t *data, int *n, int stream);
char *_getenv(char *var, data_t *data);
char *_which(char *cmd, data_t *data);
char *exeFixer(char *cmd, data_t *data);
int isDir(char *path);
void Notfound(data_t *data);
void operatorChecker(char *cmd, int *and, int *or, int *semiCo);
int commandsCounter(data_t *data);
char *opSep(data_t *data);
void commentHandler(data_t *data);
int tokCompare(char *tok, int *sep, int *flag);
int tokChecker(char *tok);

/******file_handlers***********/
int openFile(data_t *data);
void closeFile(data_t *data, int fd);

/*******BUILT-IN***************/
int builtinCheck(data_t *data, char *cmd);
int (*get_builtin(char *arg))(data_t*);
int builtin_exit(data_t *data);
int builtin_env(data_t *data);
int builtin_cd(data_t *data);

/*********getline**************/
int _getLine(data_t *data, int *size, int stream);

/*********STRTOK***************/
char **_strtok(char *str, const char *delim, int *size);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);
int isDelim(char c, const char *delim);

/********STR_HELPERS***********/
void _puts(char *s, int stream);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
int _strchr2(char *s, char c);

/*******MEMORY_USAGE***********/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freeData(data_t *data);
void freeSarray(char **arr, int size);
char *_memcpy(char *dest, char *src, unsigned int n);

/*******MORE_HELPERS**********/
int _isDigit(char *s);
void print_int(int n, int stream);

#endif
