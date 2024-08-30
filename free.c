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
