#include "shell.h"

/**
 * builtin_ctrlr - controller for builtin functions
 * @inputs: command given
 * @tokens: tokens as args
 * Return: 0 if not found, 1 if found
 */
int builtin_ctrlr(char **tokens, char *inputs)
{
	if (_strcmp(inputs, "exit") == 0)
	{
		exit_sh(tokens);
		return (1);
	}

	if (_strcmp(inputs, "env") == 0)
	{
		env_sh(tokens);
		return (1);
	}

	if (_strcmp(inputs, "setenv") == 0)
	{
		_set_nev_sh(tokens);
		return (1);
	}

	if (_strcmp(inputs, "unsetenv") == 0)
	{
		_unsetenv_sh(tokens[1]);
		return (1);
	}
	return (0);
}
