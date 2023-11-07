#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[30] = "Hello_world_bello be_you am";
	char *s = malloc(sizeof(char) * 30);
	int len = -1;

	while (1)
	{
		s = strtok(str + len + 1, "_");
		if (s == NULL)
			break;
		len += strlen(s);
		printf("%s--", s);
	}
	return (0);
}
