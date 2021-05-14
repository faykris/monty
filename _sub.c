#include "monty.h"
/**
 * _sub - Function that substracts the top two elements of the stack
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 */
void _sub(stack_t **stack, unsigned int lines)
{
	int a = 0, b = 0;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		printf("L%d: can't sub, stack too short\n", lines);
		free(f_struct.buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*stack)->n;
		b = (*stack)->prev->n;
		tmp = *stack;
		*stack = (*stack)->prev;
		(*stack)->n = b - a;
		free(tmp);
	}
}
