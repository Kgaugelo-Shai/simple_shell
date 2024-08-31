#include "shell.h"
/**
 * _cd_dir - parses path
 * @path: destintion path
 * Return: 1 on success, 0 otherwise
 */
int _cd_dir(char *path)
{
	char *_root = NULL;

	if (path == NULL)
		path = DD;

	if (_strcmp(path, "cd") == 0)
		_root = _getenv(HOME_DIR);
	else if (path[0] == '\0' || _strcmp(path, DD) == 0)
		_root = _getenv(HOME_DIR);
	else
		_root = path;

	if (_root == NULL)
	{
		perror("root path is null");
		return (0);
	}

	if (chdir(_root) != 0)
	{
		perror("could not change directory");
		return (0);
	}

	return (1);
}
