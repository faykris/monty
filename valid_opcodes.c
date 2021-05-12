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
	int i;
	char *opcode;

	opcode = malloc(sizeof(char) * 5);
	for (i = 0; buffer[i]; i++)
	{
	/*	opcode = buffer[i] + buffer[i + 1] + buffer[i + 2] + buffer[i + 3]; */
		if (_strncmp(opcode, "push", 4) == 0)
		{
			printf("Estoy en funcion de push\n");
		}
		else if (_strncmp(opcode, "pall", 4) == 0)
		{
			printf("Estoy en funcion de pall\n");
		}
	}
	printf("Imprimir linea: %d\n", lines);
	stack = stack; /* mientras miro como usarlo */
}
