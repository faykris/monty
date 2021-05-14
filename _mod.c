#include "monty.h"
/**
 * _mod - Function that divides the second top element of the stack
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 */
void _mod(stack_t **stack, unsigned int lines)
{
	int a = 0, b = 0;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		printf("L%d: can't mod, stack too short\n", lines);
		free(f_struct.buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", lines);
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
		(*stack)->n = b % a;
		free(tmp);
	}
}
