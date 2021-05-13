#include "monty.h"
char *token2 = NULL;
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
	char  *buffer = NULL;
	stack_t *stack = NULL;
	FILE *fp;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &bytes, fp) != EOF)
	{
		lines++;
		valid_opcodes(buffer, lines, &stack);
	}
	free(buffer);
	return (0);
}
