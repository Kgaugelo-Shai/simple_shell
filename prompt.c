#include "shell.h"

/**
 * _puts - prints string to STDOUT_FILENO
 * @str: string to print
 */
void _puts(char *str)
{
    size_t len = strlen(str);


    if ((write(STDOUT_FILENO, str, len)) == -1)
        perror("Could not write");
}


/**
 * prompt - prints prompt "$ " to terminal
 * @fd: file descriptor of type int
 */
void _prompt(int fd)
{
	/* if shell is in interactive mode print prompt */
	if (isatty(fd))
	{
		_puts(PROMPT); /* print prompt */
		fflush(stdout); /* flush terminal */
	}
}
