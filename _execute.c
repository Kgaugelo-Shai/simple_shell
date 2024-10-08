#include "shell.h"
/**
 * exec_cmd - executes a child command after creation
 * @fullpath: path to the command executed
 * @tokens: arguments to the command
 * Return: 0 on success -1 on failure
 */
int exec_cmd(char *fullpath, char **tokens)
{
	pid_t child;
	int status;
	char **envp = environ;

	if (tokens == NULL || *tokens == NULL || fullpath == NULL)
		return (0);
	/* create child process to execute command */
	child = fork();
	if (child == -1)
	{
		exit(EXIT_FAILURE);
	}
	/* check for child process */
	if (child == 0)
	{
		/* execute command */
		if (execve(fullpath, tokens, envp) == -1)
		{
			return (-1);
		}
	}
	else
	{
		do {
			if (waitpid(child, &status, 0) == -1)
			{
				perror("waitpid");
				return (-1); /* Indicate failure to wait */
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	/* Parent process waits for child*/
	return (0);
}
