#include "shell.h"

/**
 * _unsetenv_sh - removes an env variable from list
 * @variable: the variable  to remove
 *
 * Return: 0 on success, -1 otherwise
 */
int _unsetenv_sh(char *variable)
{
	char **env = __environ;
	int var_len;
	int i, j;
	
	var_len = strlen(variable);

	if (is_valid(variable) == 0)
		return (-1);

	for (i = 0; env[i]; i++)
	{
		if (strncmp(variable, env[i], var_len) == 0 && (env[i][var_len] == '='))
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			environ[j] = NULL;

			return (0);
		}
	}
	return (-1);
}