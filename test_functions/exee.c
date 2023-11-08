#include "main.h"

void _execve(const char *pathname, char *const argv[], char *const envp[])
{
/*	char *path;*/
	pid_t pid;
	int status, ret;

	pid = fork();
	if (pid < 0)
	{
/*		perror("fork"); */
		exit(98);
	}
	else if (pid == 0) /*child process */
	{
		ret = execve(pathname, argv, envp);
		if (ret == -1)
		{
			printf("\texited execve\n");
			perror("myshell");
			exit (98);
		}
	}
	else
	{
		wait(&status);
	}
}
