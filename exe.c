#include "main.h"

/**
 * _execve - sets up a new process for a SINGLE COMMAND
 * @pathname: path to binary or executable file or commmand
 * @argv: cmd line arguments to the new executable
 * @envp: enviroment variables
 *
 * Description: creates a new proc, pauses parent and continues afterwards
 */
void _execve(const char *pathname, char *const argv[], char *const envp[])
{
	pid_t pid;
	int status, ret;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(98);
	}
	else if (pid == 0)
	{
		ret = execve(pathname, argv, envp);
		if (ret == -1)
		{
			perror("myshell");
			exit(98);
		}
	}
	else
	{
		wait(&status);
	}
}
