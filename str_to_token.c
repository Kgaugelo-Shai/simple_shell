#include "shell.h"
/**
 * helpercreate_tokens - helper function
 * @input_cpy: input
 * Return: NOTHING
 */
void helpercreate_tokens(char *input_cpy)
{
	if (!input_cpy)
	{
		perror("strdup() failed");
		return;
	}
}
/**
 * create_tokens  - allocates memory for the tokens
 * @value: string to be tokenized
 * Return: tokens
 */
char **create_tokens(char *value)
{
	char *input_cpy, *token, *delim = " \n\t\"";
	char **tokens;
	int num_tokens = 0, i = 0, j;

	input_cpy = strdup(value);
	helpercreate_tokens(input_cpy);
	token = _strtok(value, delim);
	while (token)
	{
		num_tokens++;
		token = _strtok(NULL, delim);
	}
	num_tokens++;
	tokens = malloc(sizeof(char *) * num_tokens);
	if (!tokens)
	{
		perror("malloc() failed");
		free(input_cpy);
		return (NULL);
	}
	token = _strtok(input_cpy, delim);
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			perror("strdup() failed");
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			free(input_cpy);
			return (NULL);
		}
		token = _strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	free(input_cpy);
	return (tokens);
}
