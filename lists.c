#include "shell.h"

/**
 * add_node -puts a node to the beginning of the list.
 * @head: addr of ptr to the head node.
 * @str:strin fieldd of nodee.
 * @num:  nodee indexx used by hist.
 *
 * Return:  sizze of listt
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_l *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_l));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_l));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end -  adding a nodde to last of the list
 * @head: addr of ptr to the head nodde
 * @str:  strin fieldd of the nodde.
 * @num: nodde indexx usedd by hist.
 *
 * Return: sizze of the listt
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_l *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_l));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_l));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - printing the strin elemnt of a list_l linked list
 * @h: ptr to the 1st nodde
 *
 * Return: sizze of the listt
 */
size_t print_list_str(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		k++;
	}
	return (k);
}

/**
 * delete_node_at_index - removes nodde at gvn indexx.
 * @head: addr of the ptr to 1st nodde
 * @index: indexx of the nodde to remove.
 *
 * Return: 1 onn successs, 0 onn faillure.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_l *node, *prev_node;
	unsigned int k = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (k == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		k++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list -  freees alll noddes of a listt.
 * @head_ptr: addr of ptr to head nodde
 *
 * Return:  null
 */
void free_list(list_t **head_ptr)
{
	list_l *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

