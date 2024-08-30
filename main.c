#include "shell.h"
/**
 * main - entry point of code
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line = RESET;
	char **tokens = RESET, *fullpath = RESET;
	int child;

	while (1)
	{
		/* Prompt user for input */
		line = get_command(line);
		if (!line || !*line)/* EOF detected, exit the loop */
			break;
		/* Tokenize input into array of commands and args */
		tokens = str_to_tokens(line);
		/* Check if tokens are empty */
		if (tokens == NULL || tokens[0] == NULL)
		{
			free(tokens);   /* Free tokens if allocation failed or no input */
			tokens = RESET;  /* Reset pointer to prevent double free */
			continue;
		}
		/* Check for builtin commands */
		if (handle_builtins(tokens) == -1)
		{
			free(tokens);   /* Free tokens on error */
			tokens = RESET;  /* Reset pointer to prevent double free */
			free_reset(line);    /* Reset pointer to prevent double free */
			exit(EXIT_FAILURE);
		}
		if ((fullpath = get_fullpath(tokens[0])) == NULL)  /* Get the full path of the command */
			fullpath = tokens[0];

		child = exec_cmd(fullpath, tokens);
		if (child == -1)
			printf("%s: 1: %s: not found\n", argv[0], tokens[0]);
		/* Check if fullpath was dynamically allocated, if so, free it */
		if (fullpath != tokens[0])
		{
			free(fullpath);
			fullpath = RESET; /* Reset pointer to prevent double free */
		}
		free(tokens);    /* Free tokens after use */
		tokens = RESET;
		free_reset(line);    /* Reset pointer to prevent double free */
	}
	return 0;
}