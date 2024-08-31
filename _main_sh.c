#include "shell.h"

/**
 * main - simple shell unix shell interpreter
 * Return: 0 success
 */
int main(void)
{
	char **tokens;
	char *_command = NULL, *token;
	ssize_t cmdlen = 0;
	size_t size = 0;

	while (1)
	{
		if(isatty(STDIN_FILENO))
		{
			_puts(PROMPT);
			fflush(stdout);
		}
		if (getline(&_command, &size, stdin) == -1)
			safe_exit(_command);
		cmdlen = strlen(_command);
		if (cmdlen > 0 && _command[cmdlen - 1] == '\n')
			_command[cmdlen - 1] = '\0';
		if (cmdlen == 1 || _command[0] == '\n' || _isspace(_command) == 1)
			continue;
		hashtags(_command);
		if (_command[0] == '\0')
			continue;
		token = strtok(_command, ";\n");
		while (token)
		{
			tokens = create_tokens(token);
			if (tokens[0] == NULL || tokens[0][0] == '\0')
			{
				token = strtok(NULL, ";\n");
				continue;
			}
			eval(tokens);
			cleanup_tkns(tokens);
			token = strtok(NULL, ";\n");
		}
	}
	free(_command);
	return (0);
}
