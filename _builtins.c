#include "shell.h"

/**
 * exit_sh - exits the shell
 * Return: returns -1
 */
int exit_sh(void)
{
	return (-1);
}

/**
 * env_sh - prints the environment variable
 * Return: 0
 */
int env_sh(void)
{
	size_t i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		i++;
	}

	return (0);
}
