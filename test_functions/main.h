#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


ssize_t _read(char *buf, int fd, size_t *n);
ssize_t _getline(char **line, size_t *n, int fd);
char *m_parse(void);
char **m_token(char *line, char *del);
char **m_input(void);

void _execve(const char *pathname, char *const argv[], char *const envp[]);

#endif /* _MAIN_H_ */
