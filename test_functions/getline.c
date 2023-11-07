#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t _getline(char **line, size_t *n, int fd)
{
	ssize_t c = 0;
	char *buf = malloc(1024 * sizeof(char));

	*n = read(fd, buf, 1024);
	*line = malloc(sizeof(char) * (*n));
		for (c = 0; buf[c] != '\n'; c++)
		{
			line[0][c] = buf[c];
			if (buf[c] == EOF)
				return (-1);
		}
	line[0][c] = buf[c];
	free(buf);
	return (c + 1);
}

