#include "shell.h"

/**
 * _strcmp - compares two strings strings for likeness
 * @a: string a
 * @b: string b
 * Return: 0 if equal, > 1 or < 1 otherwise
 */
int _strcmp(char *a, char *b)
{
	int i = 0;

	for (; i < *a && i < *b; i++)
	{
		if (*a != *b)
			return (*a - *b);
		a++, b++;
	}
	return (*a - *b);
}


/**
 * _strdup - creates a dup string
 * @str: source string
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	unsigned int i = 0;
	char *str_cpy;
	unsigned int _length = 0;

	if (str == NULL)
		return (NULL);

	for (; str[_length] != '\0'; _length++)
	{
	}
	str_cpy = (char *)malloc((_length + 1) * sizeof(char));

	if (str_cpy == NULL)
		return (NULL);

	for (i = 0; i <= _length; i++)
	{
		str_cpy[i] = str[i];
	}
	return (str_cpy);
}

/**
 * _strcat - joins two strings together
 * @b: string b
 * @a: string a
 * Return: pointer to resulting string
 */
char *_strcat(char *b, char *a)
{
	int i, j;

	i = 0;
	j = 0;

	while (b[i] != '\0')
		i++;
	while (a[j] != '\0')
	{
		b[i] = a[j];
		i++;
		j++;
	}
	b[i] = '\0';
	return (b);
}


/**
 * _strcpy - copies string a and b
 * @dest: string a
 * @src: string b
 * Return: pointer to a
 */
char *_strcpy(char *dest, char *src)
{
	int ind = 0;

	for (; src[ind] != '\0'; ind++)
	{
		dest[ind] = src[ind];
	}
	dest[ind] = '\0';

	return (dest);
}


/**
 * _strtok - creates a token from a strings
 * @str: string target
 * @delim: delim
 *
 * Return: pointer to string token
 */

char *_strtok(char *str, const char *delim)
{
	char *head;
	static char *cursor;

	if (str != NULL)
		cursor = str;
	if (cursor == NULL)
		return (NULL);
	while (*cursor != '\0' && strchr(delim, *cursor) != NULL)
		cursor++;

	if (*cursor == '\0')
		return (NULL);

	head = cursor;
	while (*cursor != '\0' && strchr(delim, *cursor) == NULL)
		cursor++;

	if (*cursor != '\0')
	{
		*cursor = '\0';
		cursor++;
	}

	return (head);
}
