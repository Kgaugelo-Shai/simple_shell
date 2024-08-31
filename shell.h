#ifndef SHELL_H
#define SHELL_H

/*macros*/
#define PATH "PATH"
#define PROMPT "$ "
#define DD "~"
#define HOME_DIR "HOME"
#define PATH_MAX 4096

extern char **environ;

/*classes*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>


/* getenv */
char *_getenv(char *path);

/* eval */
int eval(char *tokens[]);

/* tokenize */
char **create_tokens(char *value);


/* issapce */
int _isspace(char *_command);

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

/* getpath */
char *fetch_path(char *cmd_path);

/* builtins */
int builtin_ctrlr(char **tokens, char *inputs);
void env_sh();
void exit_sh(char **exit_st);


/* handles comments */
void hashtags(char *_command);
/* setenv */
int is_valid(char *_command);
int key_val_env(char *key, char *value);
int _set_nev(int rw, const char *key, const char *value);
void _set_nev_sh(char **variables);

/* cd dir */
int _cd_dir(char *path);
int _custom_cd(char *path);

/* unsetenv */
int _unsetenv_sh(char *variable);
void _printenv(void);

/*util lib 1*/
int _putchar(char c);
int _strlen(char *s);
char _puts(char *str);

/* util lib 2 */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);

/* free */
void safe_exit(char *input);
void cleanup_tkns(char **tokens);

#endif
