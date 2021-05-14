#include "monty.h"

/**
 * is_number - verify if the string is a number
 * @str: string to evaluate
 *
 * Return: 1 is a numbr, 0 is not a number
 **/
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!((str[i] >= 48 && str[i] <= 57) || str[i] == '-'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
