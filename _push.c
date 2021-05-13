#include "monty.h"
/**
 * _push - Function that add an element to the top of a stack
 * @stack: Elements is a data structure
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _push(stack_t **stack, unsigned int lines)
{
	int data = 0;
	stack_t *temp = NULL;

	if (strcmp(f_struct.token2, "0") != 0 &&
		(f_struct.token2 == NULL || atoi(f_struct.token2) == 0))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", lines);
		free(f_struct.buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
	}
	data = atoi(f_struct.token2);

	if (*stack == NULL)
	{
		*stack = malloc(sizeof(stack_t));
		if (*stack == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		(*stack)->n = data;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		temp = malloc(sizeof(stack_t));
		if (temp == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		temp->prev = *stack;
		temp->n = data;
		temp->next = NULL;
		(*stack)->next = temp;
		*stack = temp;
	}
}
