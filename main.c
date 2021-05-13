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
/*	int fd = 0, i = 0, j = 0, bytes = 0; */
	size_t bytes = 0;
	unsigned int lines = 1;
	char  *buffer = NULL; /* *buf = NULL, */
	stack_t *stack_m = NULL;
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

	while (getline(&buffer, &bytes, fp) != EOF) // buf[i]
	{
		printf("linea %d: %s\n", lines, buffer);
		valid_opcodes(buffer, lines, &stack_m);
		lines++;
	}
	printf("---------------\nTotal lineas: %d\n", lines);
/*	free(buf); */
	free(buffer);
	return (0);
}
