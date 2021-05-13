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
	int fd = 0, i = 0, j = 0;
	unsigned int lines = 1;
	char *buf, *buffer;
	stack_t *stack_m = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	buf = malloc(sizeof(char) * BUFSIZ);
	buffer = malloc(sizeof(char) * BUFSIZ);
	if (buf == NULL || buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	read(fd, buf, BUFSIZ);
	close(fd);

	while (buf[i])
	{
		while (buf[i] != '\n')
		{
			buffer[j] = buf[i];
			j++;
			i++;
		}
		buffer[j]= '\0';
		valid_opcodes(buffer, av, lines, &stack_m);
		j = 0;
		lines++;
		i++;
	}
	printf("---------------\nTotal lineas: %d\n", lines);
	free(buf);
	free(buffer);
	return (0);
}
