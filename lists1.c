#include "shell.h"

/**
 * list_len - determining leng of linkked listt
 * @h:the pointer to the first node
 *
 * Return: sizze of listt.
 */
size_t list_len(const list_l *h)
{
	size_t k = 0;

	while (q)
	{
		q = q->next;
		k++;
	}
	return (k);
}

/**
 * list_to_strings - retuns an arr of str of the listt->str
 * @head: ptr to the 1st nodde
 *
 * Return: arr of str.
 */
char **list_to_strings(list_l *head)
{
	list_l *node = head;
	size_t k = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !k)
		return (NULL);
	strs = malloc(sizeof(char *) * (k + 1));
	if (!strs)
		return (NULL);
	for (k = 0; node; node = node->next, k++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < k; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[k] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list -this prints all elements of a list_t linked list
 * @h: the pointer to the first node
 * *q: ptr to
 * Return: returns the size of list
 */
size_t print_list(const list_t *q)
{
	size_t k = 0;

	while (q)
	{
		_puts(convert_number(q->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? q->str : "(nil)");
		_puts("\n");
		q = q->next;
		k++;
	}
	return (k);
}

/**
 * node_starts_with - retuns nodde whose str begins wit pre-fix
 * @node:   ptr to the listt headd
 * @prefix: str to mach
 * @c:  nxt characte afta pr-efix to mach
 *
 * Return:  mach nodde or void
 */
list_l *node_starts_with(list_l *node, char *prefix, char c)
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
 * get_node_index -acquires indexx of a nodde
 * @head: ptr to the listt headd
 * @node: ptr to the nodde
 *
 * Return:  indexx of nodde orr -1
 */
ssize_t get_node_index(list_t *head, list_l *node)
{
	size_t k = 0;

	while (head)
	{
		if (head == node)
			return (k);
		head = head->next;
		k++;
	}
	return (-1);
}

