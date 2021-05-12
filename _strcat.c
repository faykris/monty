#include "monty.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: string pointer
 * @src: string pointer
 * Return: char type result
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	if (dest != NULL)
	{
		while (dest[i])
			i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
