#include "shell.h"

/**
 * **strtow - this splits a string into words and repeat delimiters are ignored
 * @str: an input string
 * @de: a delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *de)
{
	int x, y, z, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!de)
		de = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], de) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[x], de))
			x++;
		z = 0;
		while (!is_delim(str[x + z], d) && str[x + z])
			z++;
		s[y] = malloc((z + 1) * sizeof(char));
		if (!s[y])
		{
			for (z = 0; z < y; z++)
				free(s[z]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < z; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @de: the delimeter
 * Return: the pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char de)
{
	int x, y, z, p, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != de && str[x + 1] == de) ||
				    (str[x] != de && !str[x + 1]) || str[x + 1] == de)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (str[x] == de && str[x] != de)
			x++;
		z = 0;
		while (str[x + z] != de && str[x + z] && str[x + z] != de)
			z++;
		s[y] = malloc((k + 1) * sizeof(char));
		if (!s[y])
		{
			for (z = 0; z < y; z++)
				free(s[z]);
			free(s);
			return (NULL);
		}
		for (p = 0; p < z; p++)
			s[y][p] = str[x++];
		s[y][p] = 0;
	}
	s[y] = NULL;
	return (s);
}
