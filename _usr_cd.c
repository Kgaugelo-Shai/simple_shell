#include "shell.h"

/**
 * _custom_cd - changes the current working directory
 * @path: destination path
 * Return: 1 on success, 0 otherwise
 */
int _custom_cd(char *path)
{
	char buffer[1024];
	char *str_cpy;

	str_cpy = _strdup(path);
	if (str_cpy == NULL)
	{
		perror("could not copy");
		return (0);
	}

	if (!_cd_dir(str_cpy))
	{
		free(str_cpy);
		return (0);
	}

	if (getcwd(buffer, sizeof(buffer)) == NULL)
	{
		perror("could not change directory");
		free(str_cpy);
		return (0);
	}

	free(str_cpy);
	return (1);
}
