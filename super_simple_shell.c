#include "main.h"
/**
 * main - Highest Entry Point
 *
 * Return: Status
 */
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
	}


	return (0);
}
