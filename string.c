#include "shell.h"

/**
 * _strlen - this returns the length of a string
 * @str: a string whose length to be checked
 *
 * Return:  an integer length of the string
 */
int _strlen(char *str)
{
	int x = 0;

	if (!str)
		return (0);

	while (*str++)
		x++;
	return (x);
}

/**
 * _strcmp - this performs an lexicogarphic comparison of two strings.
 * @str1: a first string
 * @str2: a second string
 *
 * Return: -ve if str1 < str2, +ve if str1 > str2, 0  if str1 == str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: a string to be searched
 * @needle: character array
 *
 * Return: an address of the  next char of the haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - this concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 *
 * Return: a pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
