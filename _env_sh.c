#include "shell.h"

/**
 * env_sh - prints the environment
 */
void env_sh()
{
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
		
}
