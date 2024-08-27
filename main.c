#include "shell.h"
/**
 * main - entry point of code
 */
int main(int argc __attribute__((unused)), char **argv)
{
    char *line = NULL;
    size_t size = 0;
    char **tokens = NULL, *fullpath = NULL;
    int child;

    while (1)
    {
        /* Prompt user for input */
        prompt(STDIN_FILENO);
        if (getline(&line, &size, stdin) == -1)
        {
            free(line);   /* Free line if getline fails */
            return (EXIT_SUCCESS);
        }
        /* Check if line is empty */
        if (strcmp(line, "\n") == 0)
        {
            free(line);   /* Free line if it's just a newline */
            line = NULL;  /* Reset pointer to prevent double free */
            continue;
        }
        /* Tokenize input into array of commands and args */
        tokens = str_to_tokens(line);
        /* Check if tokens are empty */
        if (tokens == NULL || tokens[0] == NULL)
        {
            free(tokens);   /* Free tokens if allocation failed or no input */
            tokens = NULL;  /* Reset pointer to prevent double free */
            continue;
        }
        /* Check for builtin commands */
        if (handle_builtins(tokens) == -1)
        {
            free(tokens);   /* Free tokens on error */
            tokens = NULL;  /* Reset pointer to prevent double free */
            free(line);     /* Free line on error */
            line = NULL;    /* Reset pointer to prevent double free */
            exit(EXIT_FAILURE);
        }
        /* Get the full path of the command */
        if ((fullpath = get_fullpath(tokens[0])) == NULL)
            fullpath = tokens[0];

        child = exec_cmd(fullpath, tokens);
        if (child == -1)
            printf("%s: 1: %s: not found\n", argv[0], tokens[0]);
        /* Check if fullpath was dynamically allocated, if so, free it */
        if (fullpath != tokens[0])
        {
            free(fullpath);
            fullpath = NULL; /* Reset pointer to prevent double free */
        }
        free(tokens);    /* Free tokens after use */
        tokens = NULL;
        free(line);     /* Free line on error */
        line = NULL;  /* Reset pointer to prevent double free */
    }
    return 0;
}