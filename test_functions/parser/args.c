#include <unistd.h>
#include <stdlib.h>

int _strlen(char *s);

int main(int __attribute__((unused)) argc, char **argv)
{
	char **str = argv;
	int n;
	str++;
	while (*str)
	{
		n = _strlen(*str);
		write(0, *str, n);
		write(0, "\n", 1);
		str++;
	}
	return (0);
}

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
