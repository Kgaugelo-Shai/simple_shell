#include "shell.h"
/**
 * read_input -  reads the line from user input
 * 
 * Return:
 */
char *get_input(void)
{
	char *input = NULL;
	size_t size = 0;
	ssize_t nread;

	/* print prompt */
	_prompt(STDOUT_FILENO);
	nread = getline(&input, &size, stdin);
	/* EOF or error check */
	if (nread == -1)
	{
		free(input);
		_puts("\n");
		return (NULL);
	}
	if (input[nread - 1] == '\n' && nread > 0)  /* Remove trailing '\n */
		input[nread - 1] = '\0';

	if (isspace((unsigned char)*input) || *input == '\0') /* Skip empty lines or ' ' */
	{
		free(input);
		return (get_input());
	}
	return (input);
}
