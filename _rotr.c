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
	int num1 = 0, num2 = 0;

	if (*stack == NULL)
	{
		return;
	}
	temp = *stack;

	while (temp != NULL)
	{
		if (temp->prev != NULL)
		{
			num1 = temp->n;
			num2 = temp->prev->n;
			temp->n = num2;
			temp->prev->n = num1;
		}
		temp = temp->prev;
	}
	lines = lines;
}
