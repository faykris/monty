#include "monty.h"
/**
 * _rotr - Function that rotates the stack to the bottom
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 */
void _rotr(stack_t **stack, unsigned int lines)
{
	stack_t *temp;
	int num = 0;

	if (*stack == NULL)
	{
		return;
	}
	temp = *stack;

	while (temp->prev != NULL)
		temp = temp->prev;

	num = temp->n;

	while (temp != NULL)
	{
		if (temp->next != NULL)
		{
			temp->n = temp->next->n;
		}
		else
		{
			temp->n = num;
		}
		temp = temp->next;
	}

	lines = lines;
}
