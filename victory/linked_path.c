#include "main.h"
/**
 * add_node_end - inserts a node at the end of link
 * @head: pointer to a pointer that points to list_t ele
 * @str: a string (value)
 *
 * Return: pointer to modified list
 */
paths_t *add_end(paths_t **head, char *str)
{
	paths_t *iterator;
	paths_t *new = malloc(sizeof(paths_t));

	if (str == NULL || new == NULL)
	{
		free(str);
		return (NULL);
	}

	new->path = str;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	iterator = *head;
	while (iterator->next != NULL)
		iterator = iterator->next;

	iterator->next = new;
	return (new);
}
/**
 * build_path - Entry Point into path handling
 */
paths_t *build_path(paths_t **head)
{
	char *path;
	char *path_buf = malloc(sizeof(char) * 2048);

	if (!path_buf)
		exit(15);
	*head = NULL;

	path = _getenv("PATH");
	path_buf = _strcpys(path_buf, path);
	path = _strtok(path_buf, ":");
	
	if (path == NULL)
	{
		free(path_buf);
		exit(15);
	}

	while (path)
	{
		add_end(head, path);
		path = _strtok(NULL, ":");
		if (path == NULL)
		{
			return (*head);
		}
	}
	return (*head);
}

/**
 * search_path - print all data in a linked list
 * @h: pointer to head (the starting node)
 *
 * Return: number of nodes in list
 */
char *search_path(const paths_t *h, char *pathh)
{
	const paths_t *header = h;
	int flag = 1;

	nodes = 0;
	if (h == NULL)
		return (0);
	while (flag)
	{
		if (header->path 
		if (header->next == NULL)
			flag = 0
		if (header->path != NULL)
			printf("%s\n", header->path);

		header = header->next;
	}
	return (NULL);
}

/**
 * free_list - frees a list_t list
 * @head: pointer to head node
 *
 */
void free_list(paths_t *head)
{
	int flag = 1;
	paths_t *nextt;

	free(head->path);
	while (flag)
	{
		if (head->next == NULL)
			flag = 0;
		nextt = head;
		head = nextt->next;
	/*	free(nextt->path);*/
		free(nextt);
	}
}


int main(void)
{
	paths_t *head;

	build_path(&head);
	print_list(head);
	free_list(head);

	return (0);
}
/**
 * list_len - finds the number of nodes in a list
 * @h: pointer to head (the starting node)
 *
 * Return: number of nodes in list
 */
size_t list_len(const paths_t *h)
{
	const paths_t *header = h;
	size_t nodes;
	short flag = 0;

	if (h != NULL)
		flag = 1;
	nodes = 0;
	while (flag)
	{
		if (header->next == NULL)
			flag = 0;
		nodes++;
		header = header->next;
	}
	return (nodes);
}
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
#include <string.h>

int main(int argc, char *argv[])
{
	struct stat st;
	char *path_buf, *path, full_path[1024];
	int i, k;

	i = k = 1;
	if (argc < 2)
	{
		printf("Usage: %s path_to_file ....\n", argv[0]);
		return (0);
	}

	path = _getenv("PATH");
	path_buf = malloc(sizeof(char) * (_strlen(path) + 1));
	if (path_buf == NULL)
	{
		printf("failed\n");
		exit(99);
	}

	path_buf = _strcpys(path_buf, path);
	path = _strtok(path_buf, ":");
	if (path == NULL)
	{
		free(path_buf);
		printf("failed 2\n");
		return (0);
	}
	while (argv[i] && path != NULL)
	{
		printf("token: %s", path);
		_strcpys(full_path, path);
		k = _strlen(full_path);
		full_path[k] = '/';
		full_path[k + 1] = '\0';
/*		printf("strcpy: %s\n", full_path); */
		_strcat(full_path, argv[i]);
/*		printf("full_path: %s\n", full_path); */
		printf("\t*\t%s\n", full_path);
		if (stat(full_path, &st) == 0)
		{
			printf("FOUND\n");
			i++;
		}
		else
		{
			path = _strtok(NULL, ":");
			if (path == NULL)
			{
				free(path_buf);
				printf("strtok killed\n");
				return (0);
			}
		}
	}
	if (path == NULL)
		printf("NOT FOUND!\n");
	exit(15);
}
