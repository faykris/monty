#include "monty.h"

/**
 * valid_opcodes - validates the different opcodes in a line
 * @buffer: first string to compare
 * @lines: second string to compare
 *
 * Return: none
 */
void valid_opcodes(char *buffer, char **av, unsigned int lines, stack_t **stack)
{
/*	int i;
	char *opcode; */

	char *token = NULL, delimiter[] = " ";
	int i = 0, j = 0, cmp = 0;

	instruction_t options[] = {
		{"push", _push}, {"pall", _pall}, {NULL, NULL}
	};
	
	token = strtok(buffer, delimiter);
	for (i = 0; token != NULL; i++)
	{
		av[i] = token;
		token = strtok(NULL, delimiter);
	}
	av[i] = NULL;

	while (options[j].opcode != NULL)
	{
		cmp = strcmp(av[0], options[j].opcode);
		if (cmp == 0)
		{
			options[j].f(stack, lines);
			break;
		}
		j++;
	}
	if (options[j].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", lines, av[0]);
		exit(EXIT_FAILURE);
	}
}
