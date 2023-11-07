#include <stdlib.h>
/**
 * alloc_grid - creates 2-D array and initialize to 0
 * @width: numbere of columns
 * @height: number of rows
 *
 * Return: double pointer to this array
 */

char **cmd_to_tok(char *str, char *del)
{
	unsigned int c, i, j, len = ntok = 0;
	char **arr;

	for (c = 0; str[c] != '\0'; c++)
	{
		for (j = 0; j < strlen(del); j++)
			if (s[c] == del[j])
			{
				++;
			}
		len++;
	}

	if (len <= 0 || ndel == 0)
		return (NULL);

	arr = (char **)malloc(ndel * sizeof(char *));
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	for (i = 0; i < ndel; i++)
	{
		arr[i] = (char *)malloc(width * sizeof(char));
		if (arr[i] == NULL)
		{
			for (k = i; k >= 0; k--)
				free(arr[k]);
			free(arr);
			return (NULL);
		}
	}
	return (arr);
}
