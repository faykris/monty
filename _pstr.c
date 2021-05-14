#include "monty.h"
/**
 * _pstr - Function that prints all values on the stack
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _pstr(stack_t **stack, unsigned int lines)
{
	stack_t *temp;
	char asc;

	if (*stack == NULL)
	{
		return;
	}
	else
	{
		temp = *stack;
		while (temp != NULL)
		{
			asc = putchar(temp->n);
			if ((asc >= 65 && asc <= 90) || (asc >= 97 && asc <= 122))
				printf("%c", asc);
			temp = temp->prev;
		}
		printf("\n");
	}
	lines = lines;
}