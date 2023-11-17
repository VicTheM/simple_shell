#include "main.h"

/**
 * _strspn - gets len of s containing all of accept
 * @s: longer string
 * @accept: source string
 *
 * Return: unsigned value of the number of bytes in s
 *
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int a = 0, b, t = 0;

	while (accept[a])
	{
		b = 0;

		while (s[b] != 32)
		{
			if (accept[a] == s[b])
			{
				t++;
			}

			b++;
		}

		a++;
	}

	return (t);
}

/**
 * _strpbrk - finds the first occurence of acc in s
 * @s: search string
 * @accept: buffer
 *
 * Return: pointer to the first occurence in s
 *
 */
char *_strpbrk(char *s, char *accept)
{
	char *string = s;
	char *buffer = accept;
	int ii;

	while (*string)
	{
		ii = 0;
		while (buffer[ii] != '\0')
		{
			if (*string == buffer[ii])
				return (string);
			ii++;
		}
		string++;
	}

	return ('\0');
}

/**
 * _strchr - finds a char in a string buffer
 * @s: pointer to string buffer
 * @c: char to search for
 *
 * Return: pointer to first occurence of c
 */
char *_strchr(char *s, char c)
{
	int a = 0, b;

	while (s[a])
	{
		a++;
	}

	for (b = 0; b <= a; b++)
	{
		if (c == s[b])
		{
			s += b;
			return (s);
		}
	}

	return ('\0');
}
/**
 * _strstr - finds a string in a string
 * @haystack: larger string
 * @needle: search string
 *
 * Return: pointer to begining of found string
 *
 */
char *_strstr(char *haystack, char *needle)
{
	int a = 0, b = 0;

	while (haystack[a])
	{
		while (needle[b])
		{
			if (haystack[a + b] != needle[b])
			{
				break;
			}

			b++;
		}

		if (needle[b] == '\0')
		{
			return (haystack + a);
		}

		a++;
	}

	return (NULL);
}
