#include "shell.h"
/**
 * _getenv - gets a list of env variables
 * @path: key to variable
 *Return: string of the variable
 */
char *_getenv(char *path)
{
	char **dup = __environ;
	char *val = NULL;
	int i = 0;
	size_t var_len;
	
	var_len = _strlen(path);
 
	for (; dup[i]; i++)
	{
		if (strncmp(path, dup[i], var_len) == 0 && (dup[i][var_len] == '='))
		{
			val = dup[i] + var_len + 1;
			break;
		}
	}
	return (val);
}
