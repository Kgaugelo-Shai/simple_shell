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
<<<<<<< HEAD
 * env_sh - prints the environment variable
 * Return: 0
=======
 * env_sh - builitin function that prints environment variables
>>>>>>> 884a61aae45d0fbf39f18f749838ead3ad0aa85a
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
