#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	char str[50];
	char *token;
	char *del = " ";
	int fd1 = open("Hello", O_RDONLY);
	ssize_t n = read(fd1, str, 50);
	if (n == -1)
		exit(98);

	token = strtok(str, del);
	while (token != NULL)
	{
		printf("%s**", token);
		token = strtok(NULL, del);
	}
	return (0);
}
