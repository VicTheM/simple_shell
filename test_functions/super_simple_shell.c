#include "main.h"
void screen(char *str, char *path);

int main(void)
{
	char path[1024];
	char **argv;
	char *envp[] = {NULL};

	while (1)
	{
		/* DISPLAY PROMPT AND PARSE */
		argv = m_input();
		if (argv == NULL)
			return (-1);
		screen(argv[0], path);

	/* SEARCH FOR CMD AND EXECUTE REPEAT TILL argv[n] == NULL*/
		if (path[0] == '\0')
		{
			_execve(argv[0], argv, envp);
		}
		else
		{
			_execve(path, argv, envp);
		}

		/* CLEAN UP */
		free(argv[0]);
		free(argv);
		printf("\tNew screen\n");
	}
	return (0);
}

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
