#ifndef SHELL_H
#define SHELL_H

/********Libraries***************/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
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
	char **alias;
	int flag;
	int modo;
	char *pewd;
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
	int (*f)(data_t*, int);
} builtin_t;

/******MODE_FUNCTIONS**********/
void interactive(int argc, data_t *data);
void processHandler(data_t *data);
int processHelper(data_t *dt, char **ptr, int *i, int *p, int *c, int *cmp);
void forking(data_t *data, char **cmd, char *exe, int *stat);
void dataInit(data_t *data, char *argv[], char *envp[]);

/*******FUNCTIONS**************/
int prompt(data_t *data, int *n, int stream);
char *_getenv(char *var, data_t *data);
char *_which(char *cmd, data_t *data);
char *exeFixer(char *cmd, data_t *data);
int isDir(char *path);
void Notfound(data_t *data);
void operatorChecker(char *cmd, int *and, int *or, int *semiCo);
int commandsCounter(data_t *data);
void commentHandler(data_t *data);
int tokCompare(char *tok, int *sep, int *flag);
int tokChecker(char *tok);

/*********CD_HANDLER************/
int setPWD(data_t *data, char *newDir, int p);
void _setenv(data_t *data, char *name, char *value);

/******separator***************/
char *opSep(data_t *data);
void specialVarChecker(data_t *data);
void opChar(char *line, char *nline, int *idx, int *jmp);
void specialChar(char *line, char *nline, int *i, int *jmp);

/*******$_handler**************/
void specialVarHandler(data_t *data);
void getVarValue(data_t *data, int i);

/******file_handlers***********/
int openFile(data_t *data);
void closeFile(data_t *data, int fd);

/*******BUILT-IN***************/
int builtinCheck(data_t *data, char *cmd, int idx);
int (*get_builtin(char *arg))(data_t*, int);
int builtin_exit(data_t *data, int idx);
int builtin_env(data_t *data, int idx);
int builtin_cd(data_t *data, int idx);
int builtin_setenv(data_t *data, int idx);
int builtin_aliases(data_t *data, int idx);

/*********environmenet*********/
char **envcpy(char **envicopy, char **envp);
int builtin_setenv(data_t *data, int idx);
int builtin_unsetenv(data_t *data, int idx);
char *envcmp(char *env, char *var);
int envCount(data_t *data);

/*********aliases**************/
char *aliasHandler(data_t *data, int pos);
void addAlias(data_t *data, char *alia);
int  printAliases(data_t *data, char *alias);

/*********getline**************/
int _getLine(data_t *data, int *size, int stream);
int lineHelper(data_t *data, int rd, int i);

/*********STRTOK***************/
char **_strtok(char *str, const char *delim, int *size);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);
int isDelim(char c, const char *delim);

/*********signals**************/
void handle_sig(UNUSED int sign);

/********STR_HELPERS***********/
void _puts(char *s, int stream);
int _putchar(char c);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strchr2(char *s, char c);
char *_strdup(char *str);

/*******MEMORY_USAGE***********/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freeData(data_t *data);
void freeSarray(char **arr, int size);
char *_memcpy(char *dest, char *src, unsigned int n);

/*******MORE_HELPERS**********/
int _isDigit(char *s);
void print_int(int n, int stream);
void itobuff(char *buff, int val);
int _atoi(char *s);
int checkOnlySpaces(char *line);
void rev_string(char *s);

#endif
