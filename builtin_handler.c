#include "shell.h"

/**
 * handle_builtins - checks if input is builtin command and executes it
 * @tokens: array of tokens containing user input
 * Return: 1 on success, -1 on failure/exit amd 0 if builtin was found
 */
int handle_builtins(char **tokens)
{
	size_t i = 0;

	builtin_cmds cmds[] = {
		{"exit", exit_sh},
		{"env", env_sh},
		{NULL, NULL}
	};
	/* check if there was a command provided */
	if (tokens == NULL || tokens[0] == NULL)
		return (1);
	/* iterate through array of commands */
	for (i = 0; cmds[i].command != NULL; i++)
	{
		if (strcmp(tokens[0], cmds[i].command) == 0)
		{
			/* execute builtin command if found */
			return ((cmds[i].p)());
		}
	}
	/* if command was not found in builtin list return 1(success) */
	return (1);
}
