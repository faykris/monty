#include "monty.h"

/**
 * valid_opcodes - Validates the different opcodes in a line
 * @buffer: First string to compare
 * @lines: Second string to compare
 * @stack: Elements is a data structure
 * Return: None
 */
void valid_opcodes(char *buffer, unsigned int lines, stack_t **stack)
{

	char *token1 = NULL, delimiter[] = " \n";
	int j = 0, cmp = 0;

	instruction_t options[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"swap", _swap}, {"nop", _nop}, {"add", _add},
		{"pop", _pop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{"stack", _stack}, {"queue", _queue}, {NULL, NULL}
	};

	token1 = strtok(buffer, delimiter);
	if (token1 == NULL || token1[0] == '#')
	{
		return;
	}
	f_struct.token2 = strtok(NULL, delimiter);

	f_struct.token2 = f_struct.token2;
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
		free(buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
	}
}
