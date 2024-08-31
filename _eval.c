#include "shell.h"

/**
 * run_cmd - executes a command with the given path
 * @path: path of the command
 * @tokens: array of arguments
 * Return: void
 */
void run_cmd( char *tokens[], char *path)
{
	if (execve(path, tokens, environ) == -1)
	{
		perror("Command not found");
		if (path)
			free(path);
		exit(EXIT_FAILURE);
	}
}

/**
 * eval - executes the command
 * @tokens: array of arguments as tokens
 * Return: void
 */
int eval(char *tokens[])
{
	char *path = NULL;
	pid_t child_pid;
	int status, isbuiltin;

	if (_strcmp(tokens[0], "cd") == 0)
	{
		if (_custom_cd(tokens[1]) != 1)
			return (1);
		return (0);
	}

	isbuiltin = builtin_ctrlr(tokens, tokens[0]);

	path = fetch_path(tokens[0]);

	if (path == NULL && !isbuiltin)
	{
		perror(tokens[0]);
		return (100);
	}
	if (isbuiltin)
	{
		if (path)
			free(path);
		return (1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error (fork)");
		if (path)
			free(path);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
		run_cmd(tokens, path);
	wait(&status);
	if (path)
		free(path);
	return (status);
}
