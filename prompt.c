#include "shell.h"

/**
 * _puts - prints string to STDOUT_FILENO
 * @str: string to print
 */

void _puts(char *str)
{
	unsigned int len;
	/* get length of string*/
	len = strlen(str);
	/* print string to STDOUT_FILENO*/
	write(STDOUT_FILENO, str, len);
}

/**
 * prompt - prints prompt "$ " to terminal
 * @fd: file descriptor of type int
 */
void prompt(int fd)
{
	/* if shell is in interactive mode print prompt */
	if (isatty(fd))
		_puts(PROMPT);
}
