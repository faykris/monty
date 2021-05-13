#include "monty.h"

/**
 * valid_opcodes - validates the different opcodes in a line
 * @buffer: first string to compare
 * @lines: second string to compare
 *
 * Return: none
 */
void valid_opcodes(char *buffer, unsigned int lines, stack_t **stack)
{

	char *token1 = NULL, delimiter[] = " \n";
	int j = 0, cmp = 0; //  1 = 0

	instruction_t options[] = {
		{"push", _push}, {"pall", _pall}, {NULL, NULL}
	};

	token1 = strtok(buffer, delimiter);
	if (token1 == NULL)
	{
		return;
	}
	token2 = strtok(NULL, delimiter);

	token2 = token2;
	while (options[j].opcode != NULL)
	{
		cmp = strcmp(token1, options[j].opcode);
		if (cmp == 0)
		{
			options[j].f(stack, lines);
			break;
		}
		j++;
	}
	if (options[j].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", lines, token1);
		exit(EXIT_FAILURE);
	}
}
