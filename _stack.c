#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack (LIFO).
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 */
void _stack(stack_t **stack, unsigned int lines)
{
	stack_t *current = NULL, *prev_ptr = NULL, *next_ptr = NULL;

	if (f_struct.format == AS_QUEUE)
	{
		if (*stack != NULL)
		{
			current = *stack;
			while (current->prev != NULL)
				current = current->prev;
			while (current != NULL)
			{
				prev_ptr = current->prev;
				next_ptr = current->next;
				current->prev = next_ptr;
				current->next = prev_ptr;
				*stack = current;
				current = next_ptr;
			}
			while ((*stack)->next != NULL)
				*stack = (*stack)->next;
		}
		f_struct.format = AS_STACK;
	}

	stack = stack;
	lines = lines;
}
