#include "shell.h"

/**
<<<<<<< HEAD
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
=======
>>>>>>> 884a61aae45d0fbf39f18f749838ead3ad0aa85a
 * prompt - prints prompt "$ " to terminal
 * @fd: file descriptor of type int
 */
void prompt(int fd)
{
	/* if shell is in interactive mode print prompt */
	if (isatty(fd))
<<<<<<< HEAD
		_puts(PROMPT);
=======
	{
		_puts(PROMPT); /* print prompt */
		fflush(stdout); /* flush terminal */
	}
		
>>>>>>> 884a61aae45d0fbf39f18f749838ead3ad0aa85a
}
