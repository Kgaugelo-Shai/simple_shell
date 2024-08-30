#include "shell.h"
/**
 * main - entry point of code
 */
int main(void)
{
	char *input;
	char **tokens;
	int child;
	char *fullpath;
	char *path;
	int _flag = 0;

	while (1)
	{
		/* Prompt user for input */
		input = get_input();
		if (!input || !*input)
		{
			free(input);
			break;
		}
		/* Tokenize input into array of commands and args */
		tokens = str_to_tokens(input, DELIM);
		free(input);
		/* Check if tokens are empty */
		if (tokens == NULL || tokens[0] == NULL)
		{ /* Reset pointer to prevent double free */
			continue;
		}
		path = getenv(PATH);
		if (!path) {
            path = "";
        }
		/* get full path*/
		fullpath = get_fullpath(path, tokens[0]);
		if (fullpath == NULL)
		{
			fullpath = strdup(tokens[0]);
			_flag = 1;
		}
		/* execute command*/
		child = exec_cmd(fullpath, tokens);
		if (child == -1)
			perror(tokens[0]);
		cleanup_tokens(tokens);
		clean_paths(fullpath, _flag);
	}
	return 0;
}