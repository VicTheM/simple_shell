#include "main.h"

/**
 * m_parse - display prompt and gets input as an array of chars
 * @interactive: interactive mode
 *
 * Return: a malloced array containing all valid cmdline input
 */
char *m_parse(int interactive)
{
	ssize_t nread;
	char *line;
	size_t n = 0;
	char prompt[] = "$: ";

	if (interactive == 1)
		write(STDOUT_FILENO, prompt, 3);

	nread = _getline(&line, &n, STDIN_FILENO);
/*	(*line_no)++;*/
	if (nread < 1)
	{
		return (NULL);
	}

	return (line);
}

/**
 * m_token - splits a line of text into words
 * @line: pointer to begining of line of text
 * @del: str containing all chars that should divide @line
 *
 * Return: A malloced array of the words gotten
 */
char **m_token(char *line, char *del)
{
	/* Change strtok to _strtok later */
	char *token;
	int c = 0;
	char **commands = malloc(20 * sizeof(char *));
	char *line2;

	if (commands == NULL)
		return (NULL);
	line2 = malloc(_strlen(line) * sizeof(char) + 6);
	if (line2 == NULL)
	{
		free(commands);
		return (NULL);
	}

	line2[0] = '/';
	line2[1] = 'b';
	line2[2] = 'i';
	line2[3] = 'n';
	line2[4] = '/';

	_strcpy(line2 + 5, line, del);
	free(line);

	token = _strtok(line2 + 5, del);
	if (token == NULL)
	{
		free(line2);
		free(commands);
		return (NULL);
	}
	commands[0] = token;

	while (token != NULL)
	{
		token = _strtok(NULL, del);
		commands[++c] = token;
	}

	return (commands);
}

/**
 * m_input - main entry point to the parser
 * @line_no - line number
 * @interactive: interactive mode
 *
 * Return: Malloced pointer to an array of words
 */
char **m_input(unsigned long int *line_no, int interactive)
{
	char del[] = " \n";
	char *line = m_parse(interactive);

	(*line_no)++;
	if (line == NULL)
	{
		write(1, "\n", 1);
		return (NULL);
	}

	while (*line == '\n')
	{
		free(line);
		line = m_parse(interactive);

		if (line == NULL)
		{
			if (interactive == 1)
				write(1, "\n", 1);
			return (NULL);
		}
	}

	return (m_token(line, del));
}

/**
 * _getline - customized getline to handle wrongly specified PATH
 * @line: address of a pointer to char to store texts
 * @n: holds the number of character succesfully read
 * @fd: file descriptor (instead of FILE originally)
 *
 * Return: number of characters seen before \n || EOF
 */
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

	*line = malloc(sizeof(char) * ((*n) + 1));
	if (*line == NULL)
	{
		free(buf);
		return (0);
	}
	for (c = 0; buf[c] != '\n'; c++)
	{
		line[0][c] = buf[c];
	}
	line[0][c] = buf[c];
	free(buf);

	return (c + 1);
}

/**
 * _read - a remodel of the getline() system call
 * @buf: buffer to store the line in
 * @fd: file descriptor referencing where to read from
 * @n: number of chars read
 *
 * Description: This is a RECURSIVE function!
 * it handles errors like EOF, CTRL_C, CTRL_D etc
 *
 * Return: number of chars successfully read
 */
ssize_t _read(char *buf, int fd, size_t *n)
{
	/* A LIMIT OF 1024 CHARS IS IMPOSED */
	ssize_t temp = 0;
	size_t again = 0;

	temp = read(fd, buf, 1024);
	*n += temp;
	if ((temp == 0  || temp == -1) && *n > 0)
	{
		buf[*n] = '\n';
		return (*n + 1);
	}

	if (temp < 1)
		return (*n);

	if (buf[(*n) - 1] != '\n')
	{
		again = read(fd, &(buf[*n]), 1024);

		if (again < 1)
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
