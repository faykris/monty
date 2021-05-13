#include "monty.h"

/**
 * free_stack - Free all linked list stack
 * @stack: Elements of linked list stack
 *
 * Return: None.
 **/
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->prev;
		free(temp);
	}
}
