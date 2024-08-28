#include "shell.h"

/**
 * str_to_tokens - tokenizes a string
<<<<<<< HEAD
 * @str: string to
 * Return: pointer to array of tokens
 */

=======
 * str - string to
 * returns - pointer to array of tokens
 */
>>>>>>> 884a61aae45d0fbf39f18f749838ead3ad0aa85a
char **str_to_tokens(char *str)
{
	char **tokenArr; /* pointer to array of tokens*/
	char *token;
	unsigned int i;

	/* Allocate memeory for token array*/
	tokenArr = malloc(sizeof(char) * INPUT_BUFFER);
	if (tokenArr == NULL)
	{
		printf("Could not allocate memory");
		exit(EXIT_FAILURE);
	}
	/* tokenize the input str */
	token = strtok(str, " \n\t\r");
	for (i = 0; token; i++)
	{
		tokenArr[i] = token; /* store token in array */
		token = strtok(NULL, " \n\t\r"); /* get next token*/
	}
	tokenArr[i] = NULL; /* set last element of token areray to NULL */
	return (tokenArr);
}
