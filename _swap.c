#include "monty.h"
/**
 * _swap - Function that swaps the top two elements of the stack
 * @stack: Elements is a data structure
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _swap(stack_t **stack, unsigned int lines)
{
	int a = 0, b = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", lines);
		free(f_struct.buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->prev->n;

	(*stack)->n = b;
	(*stack)->prev->n = a;
}
