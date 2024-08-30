#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
/* environment vairables */
#define PROMPT "$ "
#define DELIM " \t\n\r"
#define INPUT_BUFFER 1024
#define RESET NULL
#define PATH "PATH"
extern char **environ;

/**
 * struct builtin_cmds - struct template for builtin commands
 * @command: name of the builtin command
 * @p: pointer to builtin funtion
 */
typedef struct builtin_cmds
{
	char *command;
	int (*p)(void); /* Pointer to a function */
} builtin_cmds;

/* prompt */
void _prompt(int fd);
char *get_input(void);
int _putchar(char c);
/* Middleware */
char **create_tokens(char *input);
char **str_to_tokens(char *str, const char *delim);
char *get_fullpath(char *path, char *command);


/* Controllers */
void exit_sh(char **args);
int env_sh(void);
int handle_builtins(char **tokens, int status);
int exec_cmd(char *fullpath, char**tokens);
void cleanup_tokens(char **tokens);
void clean_paths(char *fullpath, int _flag);

/* utilities */
void _puts(char *str);

#endif
