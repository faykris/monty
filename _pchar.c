#include "monty.h"
/**
 * _pchar - Function that prints all values on the stack
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _pchar(stack_t **stack, unsigned int lines)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", lines);
		free(f_struct.buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			putchar((*stack)->n);
			putchar('\n');
		}
		else
		{
			dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
					lines);
			free(f_struct.buffer);
			free_stack(stack);
			fclose(f_struct.fp);
			exit(EXIT_FAILURE);
		}
	}
	lines = lines;
}
