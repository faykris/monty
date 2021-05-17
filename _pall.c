#include "monty.h"
/**
 * _pall - Function that prints all values on the stack
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _pall(stack_t **stack, unsigned int lines)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return;
	}
	else
	{
		temp = *stack;
		if (f_struct.format == AS_QUEUE)
		{
			while (temp->prev != NULL)
			{
				temp = temp->prev;
			}
			while (temp != NULL)
			{
				printf("%d\n", temp->n);
				temp = temp->next;
			}
		}
		else
		{
			while (temp != NULL)
			{
				printf("%d\n", temp->n);
				temp = temp->prev;
			}
		}
	}
	lines = lines;
}
