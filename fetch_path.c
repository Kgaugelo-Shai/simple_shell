#include "shell.h"

/**
 * fetch_path - searches for cmd_path in dir
 * @cmd_path: command given by user
 * Return: pointer to path or NULL
 */
char *fetch_path(char *cmd_path)
{
	char *path = _getenv("PATH"), *str_cpy;
	char *dir_path, *token;
	int path_len;
	int len_dir;

	if (cmd_path[0] == '/' || cmd_path[0] == '.')
	{
		if (access(cmd_path, F_OK) == 0)
			return (_strdup(cmd_path));
		else
			return (NULL);
	}

	if (path)
	{
		str_cpy = _strdup(path);
		path_len = _strlen(cmd_path);
		token = _strtok(str_cpy, ":");
		while (token)
		{
			len_dir = _strlen(token);
			dir_path = malloc(sizeof(char) * (path_len + len_dir + 2));
			_strcpy(dir_path, token);
			_strcat(dir_path, "/");
			_strcat(dir_path, cmd_path);
			_strcat(dir_path, "\0");
			if (access(dir_path, F_OK) == 0)
			{
				free(str_cpy);
				return (dir_path);
			}
			else
			{
				free(dir_path);
				token = _strtok(NULL, ":");
			}
		}
		free(str_cpy);
		return (NULL);
	}
	return (NULL);
}
