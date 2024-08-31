#include "shell.h"
/**
 * cleanup_tkns - frees token array
 * @tokens: tokens allocated
 * Return: void
 */
void cleanup_tkns(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}

	free(tokens);
}

/**
 * safe_exit - frees memory and exits safely
 * @input: trash
 */
void safe_exit(char *input)
{
	/*_puts("Goodbye Lagend :)\n");*/
	_putchar('\n');
	free(input);
	exit(EXIT_SUCCESS);
}