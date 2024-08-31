#include "shell.h"
/**
 * _set_nev_sh - create a new shell variable
 * @variables: array of args
 * Return: void
 */
void _set_nev_sh(char **variables)
{
	int count = 0;

	for (count = 0; variables[count] != NULL; count++)
		;

	if (count == 3)
	{
		_set_nev(1, variables[1], variables[2]);
	}
	else
	{
		perror("setenv failed (Abort)");
	}
}
