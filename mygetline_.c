#include "shell.h"
/**
 * my_getline - reads from a stdin
 * @lineptr: pointer to line memory
 * @size: size of allocaed memory
 * @stream: where input is coming from
 *
 * Return: n bytes read
 */

ssize_t my_getline(char **lineptr, size_t *size, FILE *stream)
{
	char *str_holder;
	ssize_t nread;
	ssize_t ind = 0, j;

	if (!lineptr || !size || !stream)
		return (-1);
	if (*size == 0)
		*size = 100;
	str_holder = malloc(*size + 1);
	if (!str_holder)
		return (-1);
	nread = read(fileno(stream), str_holder, *size);
	if (nread < 0)
	{
		free(str_holder);
		return (-1);
	}
	while (str_holder[ind] != '\n' && str_holder[ind] != '\0')
		ind++;

	str_holder[ind] = '\0';
	if (*lineptr == NULL)
	{
		*lineptr = malloc(ind + 1);
		if (!lineptr)
			return (-1);
	}
	for (j = 0; j <= ind; j++)
	{
		(*lineptr)[j] = str_holder[j];
	}
	free(str_holder);
	return (ind);
}
