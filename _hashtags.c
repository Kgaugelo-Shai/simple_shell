#include "shell.h"
/**
 * hashtags - swaps # with null pointers
 * @_command: the command
 * Return: void
 */
void hashtags(char *_command)
{
	int hashtags = 0;
	int len;

	for (len = 0; _command[len] != '\0'; len++)
	{
		if ((_command[len] == '\'' || _command[len] == '\"') && !hashtags)
			hashtags = 1;
		else if ((_command[len] == '\'' || _command[len] == '\"') && hashtags)
			hashtags = 0;
		else if (!hashtags && _command[len] == '#')
		{
			if (len == 0 || _command[len - 1] == ' ')
			{
				_command[len] = '\0';
				break;
			}
		}
	}
}
