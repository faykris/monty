#include "monty.h"

/**
 * _atoi - Iterative function to implement atoi() function
 * @s: string to be converted
 *
 * Return: long value result of casting
 */
long _atoi(const char *s)
{
	long num = 0;
	int i = 0;

	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}

	return (num);
}
