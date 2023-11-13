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
	int j, k, i;

	i = 0;
	k = -1;
	/* strip trailing delimeters */
	do {
		k++;
		for (j = 0; j < _strlen(delim); j++)
		{
			if (str[k] == delim[j])
				break;
		}
	} while (str[k] == delim[j] && str[k] != '\n' && str[k] != '\0');

	i = k;
	if (str[k] == '\n' || str[k] == '\0')
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

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: Where string is stored
 * @src: string
 * @trail: strip off this string at beginning
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src, char *trail)
{
	int i, j, k;

	j = -1;
	i = 0;

	/* strip trailing delimeters */
	do {
		j++;
		for (k = 0; k < _strlen(trail); k++)
		{
			if (src[j] == trail[k])
				break;
		}
	} while (src[j] == trail[k] && src[j] != '\0' && src[j] != '\n');

	while (!(src[j] == '\n' || src[j] == '\0'))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\n';

	return (dest);
}
