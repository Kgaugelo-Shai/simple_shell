#include "shell.h"

char *get_command(char *line)
{
	size_t size = 0;

    prompt(STDIN_FILENO);
    if (getline(&line, &size, stdin) == -1)
    {
        free(line);   /* Free line if getline fails */
        return (EXIT_SUCCESS);
    }
    /* Check if line is empty */
    if (strcmp(line, "\n") == 0)
    {
        free_reset(line);  /* Reset pointer to prevent double free */
    }
    return (line);
}
