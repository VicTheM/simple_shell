/* My own C library functions */
#include "main.h"

/**
 * _strtok - man strtok
 * @str: string to tokenize
 * @delim: string holding all delimeters
 * Description: spilts a string
 *
 * Return: null terminated words (token)
 */
char *_strtok(char *str, const char *delim)
{
	static char *new;

	if (str) /*first call */
	{
		new = NULL;
		str = search(&new, str, delim);
		return (str);
	}

	else /* Subsequent call */
	{
		if (new)
		{
			str = new;
			str = search(&new, str, delim);
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}


/**
 * search - replaces delimeters in a str with '\0'
 * @neww: pointer set to after delimeter or NULL
 * @str: string to parse
 * @delim: array of delimeter characters
 *
 * Return: pointer to token
 */
char *search(char **neww, char *str, const char *delim)
{
	int j, c, k, i;

	k = i = 0;
	do {
		c = 0;
		while (c < _strlen(delim))
		{
			if (str[k] == delim[c])
			{
				k++;
				c = 0;
			}
			else
			{
				c++;
			}
		}
	} while (str[k] == delim[c] && str[k] != '\0');
	i = k;
	if (str[k] == '\0')
	{
		*neww = NULL;
		return (NULL);
	}
	while (str[k] != '\0')
	{
		for (j = 0; j < _strlen(delim); j++)
		{
			if (str[k] == delim[j])
			{
				str[k] = '\0';
				*neww = &str[k + 1];
				return (str + i);
			}
		}
		k++;
	}
	*neww = NULL;
	return (str + i);
}

/**
 * _strlen - man strlen
 * @str: pointer to char
 *
 * Return: length of @str str[len] = '\0'
 */
long int _strlen(const char *str)
{
	long int len = 0;

	if (str == NULL)
		return (0);

	while (str[len] != '\0')
		len++;

	return (len);
}
