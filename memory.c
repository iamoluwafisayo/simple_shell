#include "shell.h"

/**
 * bfree - frees the pointer to NULL the address
 * @ptr: an address of the the pointer to be freed
 *
 * Return: 1 if freed, else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
