#include "monty.h"

void _push(stack_t **stack, unsigned int lines)
{
	int data = 0;
	stack_t *temp = NULL;

	if (strcmp(token2, "0") != 0 && (token2 == NULL || atoi(token2) == 0))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", lines);
		exit(EXIT_FAILURE);
	}
	data = atoi(token2);
	
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
void _pall(stack_t **stack, unsigned int lines)
{
	if(*stack == NULL)
	{
		return;
	}
	else
	{
		while(*stack != NULL)
		{
			printf("%d\n",(*stack)->n);
			*stack = (*stack)->prev;
		}
	}
	lines = lines;
}
