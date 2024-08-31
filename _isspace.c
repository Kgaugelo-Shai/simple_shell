#include "shell.h"
/**
 * _isspace - checks for space or tab
 *@_command: input to parse
 *Return: 1 if space, else 0
 */
int _isspace(char *_command)
{
	int indx = 0;

	while (_command[indx])
	{
		if (_command[indx] == ' ' || _command[indx] == '\t')
			indx++;
		else
			return (0);
	}

	return (1);
}
