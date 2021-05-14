#include "monty.h"

/**
 * main - monty interpreter main process
 * @ac: points to the previous element of the stack (or queue)
 * @av: points to the next element of the stack (or queue)
 *
 * Return: 0 is successful, otherwise in a error code
 */
int main(int ac, char **av)
{
	size_t bytes = 0;
	unsigned int lines = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f_struct.fp = fopen(av[1], "r");
	if (f_struct.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&f_struct.buffer, &bytes, f_struct.fp) != EOF)
	{
		lines++;
		valid_opcodes(f_struct.buffer, lines, &stack);
	}
	free(f_struct.buffer);
	free_stack(&stack);
	fclose(f_struct.fp);
	return (0);
}
