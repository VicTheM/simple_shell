#include "main.h"

int find_str(char *hay, char *needle, int n)
{
	int start = 0;
	int found =  -1;
	int i, k, next;

	i = k = 0;
	next = 0;;
	while (i < n && !(hay[i] == '\0' || hay[i] == '\n') && !(needle[k] == '\0' || needle[k] == '\n'))
	{
		if (hay[k] == '\n' || hay[k] == '\0')
			return (-1);
		if (needle[k] == hay[i])
		{
			k++;
			i++;
			if ((needle[k] == '\n' || needle[k] == '\0') && needle[0] == hay[start] && (needle[1] == hay[start + 1] || needle[1] == '\n' || needle[1] == '\0'))
			{
				found = start;
				break;
			}
		}
		else
		{
			next++;
			start = i = next;
			k = 0;
			found = -1;
		}
	}
	return (found);
}

/**
 * _strcat - concantenate two strings
 * @dest: pointer to first string
 * @src: pointer to second string
 *
 * Return: pointer to concantenated string
 *
 */

char *_strcat(char *dest, char *src)
{
	char *one = dest;
	char *two = src;
	int len1;

	len1 = 0;
	while (*one != '\0' && *one != '\n')
	{
		++len1;
		one++;
	}
	while (*two != '\n' && *two != '\0')
	{
		dest[len1] = *two;
		two++;
		len1++;
	}
	dest[len1] = '\0';
	return (dest);
}

/**
 * _strncat - concantenate two strings
 * @dest: pointer to first string
 * @src: pointer to second string
 * @n: number of bit in src to add
 *
 * Return: pointer to concantenated string
 *
 */

char *_strncat(char *dest, char *src, int n)
{
	char *one = dest;
	char *two = src;
	int ii;

	ii = 0;
	while (*one)
	{
		one++;
	}
	while (ii < n && *two)
	{
		*one++ = *two;
		two++;
		ii++;
	}
	*one = '\0';
	return (dest);
}

/**
 * _strcmp - compares two stsrings
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: signed int
 *
 */

int _strcmp(char *s1, char *s2)
{
	if (*s1 > *s2 || *s2 > *s1)
		return (*s1 - *s2);
	else
		return (0);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: Where string is stored
 * @src: string
 * Return: dest
 */
char *_strcpys(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
