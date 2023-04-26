#include "shell.h"

/**
 **_strncpy - this copies a string
 *@dest: destination where the string is to be copied to
 *@src: source string
 *@n: amount of characters that are to be copied
 *Return: the string been concatenated 
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}

/**
 **_strncat - concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes at maximum use
 *Return: the string been concatenated
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@str: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

