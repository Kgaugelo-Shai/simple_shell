#include "shell.h"
/**
 * exit_sh - exits the programs safely
 * @exit_st: status of exit
 * Return: void
 */
void exit_sh(char **exit_st)
{
	int indx = 0;

	for (indx = 0; exit_st[indx] != NULL; indx++)
		;
	if (indx == 1)
	{
		free(exit_st);
		exit(0);
	}
	else if (indx == 2)
	{
		int status = atoi(exit_st[1]);

		free(exit_st);
		exit(status);
	}
	else
	{
		perror("exit failure");
		free(exit_st);
		exit(2);
	}
}
