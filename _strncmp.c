#include "monty.h"

/**
 * _strlen - function that returns the length of a string
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 is n charaters are equal, on error different value
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (i != n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
