#include "monty.h"

/**
 * read_textfile - reads a text file and prints it to
 *				the POSIX standard output
 * @filename: name of file to read
 * @letters: quantity of letters
 *
 * Return: Always 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = 0;
	unsigned int r = 0, w = 0;
	char *buf;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buf = malloc(sizeof(char) * letters);
	r = read(fd, buf, letters);

	close(fd);

	w = write(STDOUT_FILENO, buf, r);

	free(buf);
	if (r == w)
	{
		return (w);
	}
	return (0);
}