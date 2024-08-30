#include "shell.h"

/**
 * free_reset - frees allocated memory and resets it
 * @line: memory to be freed
 */
void free_reset(char *line)
{
	free(line);
	line = RESET;
}
/**
 * cleanup_tokens - frees memory allocated to an array
 * @tokens: pointer to alloc memory location
 *
 * Return: void.
 */
void cleanup_tokens(char **tokens) {
    int i;

    if (!tokens) return;

    for (i = 0; tokens[i]; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

/**
 * clean_paths - frees allc mem
 */
void clean_paths(char *fullpath, int _flag)
{
    if (_flag == 1)
        free(fullpath);
}
