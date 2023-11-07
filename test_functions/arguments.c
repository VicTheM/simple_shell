#include <unistd.h>
#include <stdlib.h>

int _strlen(char *s);

int main(int __attribute__((unused)) argc, char **argv)
{
	char **str = argv;
	int i, n, offset, j, k;
	char *buf = malloc(1024 * sizeof(char));

	str++;
	offset = 0;
	while (*str)
	{
		j = 0;
		n = k = _strlen(*str);
		do
		{
			for (i = offset; i < n && i < (offset + 1024); i++)
			{
				buf[i - offset] = str[0][n - k];
				k--;
			}
			if (i == 1024)
			{
				write(0, buf, 1024);
				offset = 1024;
				continue;
			}
			buf[i - offset] = '\n';
			i++;
			j += i;
			offset = 0;
			str++;
		} while (*(str + 1) && j < 1024);
		write(0, buf, j);
		str++;
	}
	free(buf);
	return (0);
}

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
