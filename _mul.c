#include "monty.h"
/**
 * _mul - Function that multiples of second top element
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 */
void _mul(stack_t **stack, unsigned int lines)
{
	int a = 0, b = 0;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		printf("L%d: can't mul, stack too short\n", lines);
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
		(*stack)->n = a * b;
		free(tmp);
	}
}
