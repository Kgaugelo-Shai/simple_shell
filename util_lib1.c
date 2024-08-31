#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _strlen - returns len of str
 * @str: string to use
 * Return: the length as int
 */
int _strlen(char *str)
{
	char *pointer = str;

	while (*pointer)
		pointer++;
	return (pointer - str);
}


/**
 * _puts - prints a string to stdout given
 * @str: string to print
 * Return: pointer to the string created
 */
char _puts(char *str)
{
	int ind;

	for (ind = 0; str[ind] != '\0'; ind++)
	{
		_putchar(str[ind]);
	}
	return (str[ind]);
}


