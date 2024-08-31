#include "shell.h"

/**
 * is_valid - checks for a given _command in envp variable
 * @_command: command to search for
 * Return: 1 if command exist, 0 otherwise
 */
int is_valid(char *_command)
{
	char **envp = __environ;
	int i;
	int cmd_len;
	
	cmd_len = strlen(_command);
	if (cmd_len == 0)
		return (0);

	for (i = 0; envp[i]; i++)
	{
		if (strncmp(_command, envp[i], cmd_len) == 0 && (envp[i][cmd_len] == '='))
			return (1);
	}

	return (0);
}

/**
 * key_val_env - create key value pairs of envp variables
 * @key: key of variable
 * @value: the value 
 * Return: 0 on success, 1 on failure
 */
int key_val_env(char *key, char *value)
{
	char *full_name;

	if (!key || !value)
		return (1);

	full_name = malloc(strlen(key) + strlen(value) + 2);
	strcpy(full_name, key);
	strcat(full_name, "=");
	strcat(full_name, value);

	if (putenv(full_name) != 0)
	{
		free(full_name);
		return (1);
	}

	return (0);
}
/**
 * _printenv - prints env varia bles
 * Return: void
 */
void _printenv(void)
{
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
		
}
/**
 * _set_nev - sets the vale of a env variable
 * @key: key of the selected variable
 * @value: the value
 * @rw: overwrite safety
 * Return: 0 on success, 1 otherwise
 */
int _set_nev(int rw, const char *key, const char *value)
{
	if (rw)
	{
		if (key_val_env((char *)key, (char *)value) == 0)
		{
			_printenv();
			return (0);
		}
	}
	else
	{
		if (is_valid((char *)key) != 1)
		{
			if (key_val_env((char *)key, (char *)value) == 0)
			{
				_printenv();
				return (0);
			}
		}
	}

	return (1);
}
