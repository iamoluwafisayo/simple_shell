#include "shell.h"

/**
 * list_len - this determines the length of a linked list
 * @p: a pointer to the first node
 *
 * Return: the size of a list
 */
size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * list_to_strings - this returns an array of strings for the list->str
 * @head: a pointer to the  first node
 *
 ad;
	size_t x = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)* Return: an array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = he
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < x; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}


/**
 * print_list - this  prints all the elements of a list_t linked list
 * @h: a pointer to the first node
 *
 * Return: the size of the list
 */
size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * node_starts_with - this  returns the node whose string starts with a prefix
 * @node: a pointer to the list head
 * @prefix: a string to match
 * @c: the next character after the prefix to be matched with
 *
 * Return: match node / null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - this gets the index of a node
 * @head: a pointer to a  list head
 * @node: a pointer to the node
 *
 * Return: index of node 0  else  -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}

