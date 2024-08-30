#include "shell.h"

void exit_sh(char **args)
{
	int status = -1;

	if (args[1])
	{
		status = atoi(args[1]);
	}
	cleanup_tokens(args);
	exit(status);
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
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}

	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}