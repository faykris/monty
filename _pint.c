#include "monty.h"
/**
 * _pint - Function that prints the top elemnt of a stack
 * @stack: Elements is a data structure
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _pint(stack_t **stack, unsigned int lines)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", lines);
		free(f_struct.buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	lines = lines;
}
