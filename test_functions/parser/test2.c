#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str = malloc(sizeof(char) * 20);
	ssize_t nread = read(0, str, 19);

	str[nread] = '\0';
	printf("--nread: %li--%s\n", nread, str);
	return (0);
}
