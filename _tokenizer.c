#include "shell.h"

/**
 * create_tokens - Tokenizes a string into an array of tokens using a delimiter.
 * @str: The string to tokenize.
 * @delim: The delimiter used to split the string.
 *
 * Return: A pointer to an array of tokens (strings), or NULL if an error occurs.
 */
char **create_tokens(char *input)
{
	char **tokens = NULL;
	char *str_copy = NULL;

	/* Create a duplicate of the string to avoid modifying the original */
	str_copy = strdup(input);
	if (str_copy == NULL)
	{
		_puts("Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}

	tokens = str_to_tokens(str_copy, " \t\n\r");
	/* Free the duplicated string */
	free(str_copy);

	return (tokens);
}
/**
 * tr_to_tokens - creates tokens from a given string
 */
char **str_to_tokens(char *str, const char *delim)
{
	char **args;
	char *token;
	size_t i = 0;
	size_t size = 10; /* Initial size of the array */

	args = malloc(size * sizeof(char *)); /* Allocate init memory for array */
	if (!args)
		return (NULL);
	token = strtok(str, delim);  /* Tokenize the string */
	while (token)
	{
		if (i >= size - 1) /* Reallocate memory if needed */
		{
			size *= 2; /* Double the size for the next reallocation */
			args = realloc(args, size * sizeof(char *));
			if (!args)
				return (NULL);
		}
		args[i] = malloc(strlen(token) + 1); /* Allocate memory for each token */
		if (!args[i])
		{
			cleanup_tokens(args);
			return (NULL);
		}
		strcpy(args[i], token); /* Copy the token into the newly allocated memory */
		token = strtok(NULL, delim);
		i++;
	}
	args = realloc(args, (i + 1) * sizeof(char *)); /* Resize the array */
	if (!args)
	{
		while (i-- > 0)
			free(args[i]);
		return (NULL);
	}
	args[i] = NULL; /* NULL terminate the array of tokens */
	return (args);
}