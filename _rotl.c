#include "monty.h"
/**
 * _rotl - Function that rotates the stack to the top
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 */
void _rotl(stack_t **stack, unsigned int lines)
{
	stack_t *temp;
	int num = 0;

	if (*stack == NULL)
	{
		return;
	}
	temp = *stack;

	num = (*stack)->n;

	while (temp != NULL)
	{
		if (temp->prev != NULL)
		{
			temp->n = temp->prev->n;
		}
		else
		{
			temp->n = num;
		}
		temp = temp->prev;
	}

	lines = lines;
}
