#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* environment vairables */
#define PROMPT "$ "
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

/* config */
void prompt(int fd);

/* Middleware*/
char **str_to_tokens(char *str);
char *get_fullpath(char *command);
void free_reset(char *line);
char *get_command(char *input);
/* Controllers */
int exit_sh(void);
int env_sh(void);
int handle_builtins(char **tokens);
int exec_cmd(char *fullpath, char**tokens);

/* utilities */
void _puts(char *str);

#endif
