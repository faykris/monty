#include "monty.h"
/**
 * _pall - Function that prints all values on the stack
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _pall(stack_t **stack, unsigned int lines)
{
	if (*stack == NULL)
	{
		return;
	}
	else
	{
		while (*stack != NULL)
		{
			printf("%d\n", (*stack)->n);
			*stack = (*stack)->prev;
		}
	}
	lines = lines;
}
