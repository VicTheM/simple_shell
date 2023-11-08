#include "main.h"
/* void screen(char *str, char *path); */

int main(void)
{
	char **argv;
	char *envp[] = {NULL};
/* How can I make the code not to exit when ctrl-c is pressed? */
	while (1)
	{
		/* DISPLAY PROMPT AND PARSE */
		argv = m_input();
		if (argv == NULL)
		{
			return (0);
		}

	/* SEARCH FOR CMD AND EXECUTE REPEAT TILL argv[n] == NULL*/
		if (argv[0][0] != '~' && argv[0][0] != '/' && argv[0][0] != '.')
			_execve(argv[0] - 5, argv, envp);
		else
			_execve(argv[0], argv, envp);

		/* CLEAN UP */
		free(argv[0] - 5);
		free(argv);
		printf("\tNew screen\n");
	}
	return (0);
}
/*
void screen(char *str, char *path)
{
	if (str[0] != '~' && str[0] != '/' && str[0] != '.')
	{
		path[0] = '/';
		path[1] = 'b';
		path[2] = 'i';
		path[3] = 'n';
		path[4] = '/';
		strcpy(path + 5, str);
		printf("\t---%s---\n", path);
	}
	else
	{
		path[0] = '\0';
	}
}
*/
