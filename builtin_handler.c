#include "shell.h"

/**
 * handle_builtins - checks if input is builtin command and executes it
 * @tokens: array of tokens containing user input
 * Return: 1 on success, -1 on failure/exit amd 0 if builtin was found
 */
int handle_builtins(char **tokens)
{
	if (!tokens[0])
		return (0);
	if (!strcmp(tokens[0], "exit"))
	{
		exit_sh(tokens);
		return (1);
	}
	else if (!strcmp(tokens[0], "env"))
		env_sh();
	else
		return (0);
	return (1);
}
