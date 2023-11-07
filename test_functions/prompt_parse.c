#include "main.h"

ssize_t _getline0(char **line, size_t *n, int fd);

char *m_parse1(void)
{
	ssize_t nread;
	char *line;
	size_t n = 0;
	char prompt[] = "$: ";

	write(STDOUT_FILENO, prompt, 3);
	nread = _getline0(&line, &n, STDIN_FILENO);
	if (nread < 1)
	{
		return (NULL);
	}

	return (line);
}


char **m_token1(char *line, char *del)
{
	char *token;
	int c = 0;
	char **commands = malloc(20 * sizeof(char *));

	token = strtok(line, del);
	commands[0] = token;
	while (token != NULL)
	{
		token = strtok(NULL, del);
		commands[++c] = token;
	}
	
	return (commands);
}

char **m_input2(void)
{
	char del[] = "\n";
	char *line = m_parse1();
	if (line == NULL)
	{
		write(1, "\n", 1);
		return (NULL);
	}

	return (m_token1(line, del));
}

ssize_t _getline0(char **line, size_t *n, int fd)
{
	ssize_t c = 0;
	char *buf = malloc(1024 * sizeof(char));

	*n = read(fd, buf, 1024);
	if (*n == 0)
		return (0);
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

int main(void)
{
	int c, i;
	char **commands = m_input2();

	if (commands == NULL)
		return (-1);
	
	c = i = 0;
	while (commands[c] != NULL)
	{
		printf("%s\n", commands[c++]);
	}
	return (0);
}
