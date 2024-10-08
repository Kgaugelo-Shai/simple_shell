#include "shell.h"

/**
 * get_fullpath - searches for PATH variable for a command
 * @command: command from user
 * Return: 1
 */
char *get_fullpath(char *command)
{
	char *path = getenv(PATH), *dup_path, *token, *fullpath;
	int tok_len, cmd_len = strlen(command);


	/* Allocate memory to hold a duplicate of PATH */
	if (!(dup_path = malloc(strlen(path) + 1)))
		return (NULL);
	/* Create a copy of the PATH variable */
	strcpy(dup_path, path);
	/* Tokenize the duplicate path */
	token = strtok(dup_path, ":");
	while (token)
	{
		tok_len = strlen(token); /* Length of the directory token */
		/* Allocate memory for fullpath */ 
		if (!(fullpath = malloc(tok_len + cmd_len + 2))) /* +2 for '/' and '\0' */
		{
			free(dup_path);
			return (NULL);
		}
		/* Create the full path name */
		strcpy(fullpath, token);
		fullpath[tok_len] = '/';
		strcpy(fullpath + tok_len + 1, command);
		fullpath[tok_len + cmd_len + 1] = '\0'; /* Null terminate the string */
		/* Check if the path exists and is executable */
		if (access(fullpath, X_OK) == 0)
		{
			free(dup_path);
			return (fullpath); /* Return the full path if executable */
		}
		/* Free memory if not executable and continue */
		free(fullpath);
		token = strtok(NULL, ":");
	}
	/* Free memory for the duplicate PATH and return NULL if not found */
	free(dup_path);
	return (NULL);
}
