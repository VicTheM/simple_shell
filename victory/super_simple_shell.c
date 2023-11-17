#include "main.h"
/**
 * main - Highest Entry Point
 *
 * Return: Status
 */
int main(int __attribute__((unused)) argc, char *argv[], char *env)
{
	paths_t *head;
	int interactive = 0;
	int i = 1;
	char *name = argv[0];
	char **argvv;
	char *envp[] = {NULL};
	unsigned long int line_no = 0;

	build_path(&head);

	if (argv[i] != NULL)
		_execve(argv[i], argv + 1, envp, name, head);

	if (isatty(STDIN_FILENO) == 1)
		interactive = 1;
	/* How can I make the code not to exit when ctrl-c is pressed? */
	while (1)
	{
		/* DISPLAY PROMPT AND PARSE */
		argvv = m_input(&line_no, interactive);
		if (argvv == NULL)
			return (-1);

		/* SEARCH FOR CMD AND EXECUTE REPEAT TILL argv[n] == NULL*/
		if (argvv[0][0] != '~' && argvv[0][0] != '/' && argvv[0][0] != '.')
			_execve(argvv[0] - 5, argvv, envp, name, head);
		else
			_execve(argvv[0], argvv, envp, name, head);

		/* CLEAN UP */
		free(argvv[0] - 5);
		free(argvv);
		if (interactive == 0)
		{
			fflush(stderr);
			break;
		}
	}
	free_list(head);
	return (0);
}
