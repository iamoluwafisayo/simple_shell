#include "shell.h"

/**
 * _history - displays history list, one command in line, preceded
 * with line numbers, starting at 0.
 * @info: Structure that contains potential arguments. Used to maintain
 *  constant function prototype.
 *  Return: Always 0. success
 */
int _history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: the parameter struct
 * @str: string alias
 *
 * Return: Always 0. on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *x, y;
	int ret;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	y = *x;
	*x = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = y;
	return (ret);
}

/**
 * set_alias - this sets alias to string
 * @info: as parameter struct
 * @str: string alias
 *
 * Return: Always 0 .success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *x;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 .success, 1 on error
 */
int print_alias(list_t *node)
{
	char *x = NULL, *a = NULL;

	if (node)
	{
		x = _strchr(node->str, '=');
		for (a = node->str; a <= x; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(x + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int  _alias(info_t *info)
{
	int i = 0;
	char *x = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		x = _strchr(info->argv[i], '=');
		if (x)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

