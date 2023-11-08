 #include "main.h"
ssize_t _read(char *buf, int fd, size_t *n);
ssize_t _getline(char **line, size_t *n, int fd);

char *m_parse(void)
{
	ssize_t nread;
	char *line;
	size_t n = 0;
	char prompt[] = "$: ";

	write(STDOUT_FILENO, prompt, 3);
	nread = _getline(&line, &n, STDIN_FILENO);
	if (nread < 1)
	{
		return (NULL);
	}
	return (line + 5);
}


char **m_token(char *line, char *del)
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

char **m_input(void)
{
	char del[] = " \n";
	char *line = m_parse();
	if (line == NULL)
	{
		write(1, "\n", 1);
		return (NULL);
	}
	while (*line == '\n')
	{
		free(line - 5);
		line = m_parse();
	}
	return (m_token(line, del));
}

ssize_t _getline(char **line, size_t *n, int fd)
{
	ssize_t c = 0;
	char *buf = malloc(1024 * sizeof(char));
	if (buf == NULL)
		return (0);

	*n = _read(buf, fd, n);
	if (*n == 0)
	{
		free(buf);
		return (0);
	}
	*line = malloc(sizeof(char) * ((*n) + 5));
	if (*line == NULL)
	{
		free(buf);
		return (0);
	}
	line[0][0] = '/';
	line[0][1] = 'b';
	line[0][2] = 'i';
	line[0][3] = 'n';
	line[0][4] = '/';
	for (c = 0; buf[c] != '\n'; c++)
	{
		line[0][c + 5] = buf[c];
	}
	line[0][c + 5] = buf[c];
	free(buf);
	return (c + 1);
}
/*
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
	free(commands[0]);
	free(commands);
	return (0);
}
*/

ssize_t _read(char *buf, int fd, size_t *n)
{
 	/* A LIMIT OF 1024 CHARS IS IMPOSED */
	size_t temp = 0;
	size_t again = 0;
	temp = read(fd, buf, 1024);
	*n += temp;
	if (temp == 0 && *n > 0)
	{
		buf[*n] = '\n';
		return (*n + 1);
	}
	if (temp == 0)
		return (*n);
	if (buf[(*n) - 1] != '\n')
	{
		again = read(fd, &(buf[*n]), 1024);
		if (again == 0)
		{
			buf[*n] = '\n';
			return (*n + 1);
		}
		if (buf[*n + again - 1] == '\n')
			return (*n + again);
		*n += again;
		return (_read(&(buf[*n]), fd, n));
	}
	return (*n);
}
