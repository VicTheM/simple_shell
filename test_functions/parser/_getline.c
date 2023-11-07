#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t _getline(char **line, size_t *n, int fd);

int main(void)
{
	ssize_t nread;
	char *line;
	size_t n = 0;
	unsigned int i = 0;
	char prompt[] = "$: ";

	write(STDOUT_FILENO, prompt, 3);
	nread = _getline(&line, &n, STDIN_FILENO);
	if (nread == -1)
		exit(98);

	while (line[i] != '\n')
		i++;

	write(STDOUT_FILENO, line, i + 1);
	free(line);
	return (0);
}
