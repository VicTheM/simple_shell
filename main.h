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
char *m_parse(int interactive);
char **m_token(char *line, char *del);
char **m_input(unsigned long int *line_no, int interactive);
char *_strtok(char *str, const char *delim);
long int _strlen(const char *str);
char *search(char **neww, char *str, const char *delim);
char *_strcpy(char *dest, char *src, char *trail);

void _execve(const char *pathname, char *const argv[], char *const envp[], char *name);

#endif /* _MAIN_H_ */
