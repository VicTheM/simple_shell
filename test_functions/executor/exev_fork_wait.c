#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void _execve(const char *pn, char *const argv[], char *const envp[]);

int main(void)
{
	pid_t p;
	char *const argv[] = {"../ls", "-l", NULL};
	char *const envp[] = {NULL};
	int k = 0;

	while (k < 5)
	{
		printf("\n\tparentpid: %ld\n", (long)getpid());
		p = fork();
		if (p < 0)
		{
			perror("fork");
			return (-1);
		}
		else if (p == 0)
		{
			/* child process */
			printf("\n\tchild: %ld\tparent: %ld\n", (long)getpid(), (long)getppid());
			_execve(argv[0], argv,  envp);
			printf("\nwill this line execute?\n");
		}
		else
		{
			/* parent */
			wait(NULL);
			k++;
		}
	}
	return (0);
}


void _execve(const char *pn, char *const argv[], char *const envp[])
{
	int ret;

	ret = execve(pn, argv, envp);
	if (ret == -1)
		perror("execve");
}
