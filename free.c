#include "shell.h"

/**
 * free_reset
 */
void free_reset(char *line)
{
    free(line);
    line = RESET;
}