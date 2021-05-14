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

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	else
	{
		temp = *stack;
		while (temp != NULL)
		{
			if (temp->n == 0 || !(temp->n >= 1  && temp->n <= 127))
			{
				break;
			}
			if ((temp->n >= 65 && temp->n <= 90) ||
				(temp->n >= 97 && temp->n <= 122))
			{
				putchar(temp->n);
			}
			temp = temp->prev;
		}
		putchar('\n');
	}
	lines = lines;
}
