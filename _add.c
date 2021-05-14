#include "monty.h"
/**
 * _add - Function that adds the top two elements of the stack
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 */
void _add(stack_t **stack, unsigned int lines)
{
	int a = 0, b = 0;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", lines);
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
		(*stack)->n = a + b;
		free(tmp);
	}
}
