#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	FILE *input;
	ssize_t nread;
	char *line;
	size_t n = 0;
	unsigned int i = 0;

	input = fdopen(STDIN_FILENO, "r");
	if (input == NULL)
		return (-1);
	write(STDOUT_FILENO, "$ ", 2);
	nread = getline(&line, &n, input);
	if (nread == -1)
		exit(98);

	while (line[i] != '\n')
	{
		i++;
	}

	write(STDOUT_FILENO, line, i + 1);
	free(line);
	return (0);
}
