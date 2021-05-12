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
	unsigned int r = 0, w = 0, lines = 0;
	char *buf, *buffer;
	stack_t *stack_m = NULL;

	if (ac != 2)
	{
		write(STDOUT_FILENO, "USAGE: monty file\n", 19);
		exit(EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDOUT_FILENO, "Can't open file ", 17);
		write(STDOUT_FILENO, av[1], _strlen(av[1]));
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}

	buf = malloc(sizeof(char) * BUFSIZ);
	buffer = malloc(sizeof(char) * BUFSIZ);
	if (buf == NULL || buffer == NULL)
	{
		write(STDOUT_FILENO, "Error: malloc failed\n", 22);
		exit(EXIT_FAILURE);
	}
	r = read(fd, buf, BUFSIZ);
	close(fd);

	w = write(STDOUT_FILENO, buf, r);

	printf("---------------\nLongitud archivo: %d\n", w);

	while (buf[i])
	{
		while (buf[i] != '\n')
		{
			buffer[j] = buf[i];
			j++;
			i++;
		}
		buffer[j]= '\0';
		valid_opcodes(buffer, lines, &stack_m);
		j = 0;
		lines++;
		i++;
	}
	printf("---------------\nTotal lineas: %d\n", lines);
	free(buf);
	free(buffer);
	return (0);
}
