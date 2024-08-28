#include "shell.h"

/**
 * prompt - prints prompt "$ " to terminal
 * @fd: file descriptor of type int
 */
void prompt(int fd)
{
	/* if shell is in interactive mode print prompt */
	if (isatty(fd))
	{
		_puts(PROMPT); /* print prompt */
		fflush(stdout); /* flush terminal */
	}
}
