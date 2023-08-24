#include "shell.h"
/**
 * add_node - add one node in a list in the beginning
 * @head: header pointer to the list
 * @str: string to be put in node
 * @num: node index
 * Return: new_list header pointer
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_header;

	if (!head)
		return (NULL);
	new_header = malloc(sizeof(list_t));
	if (!new_header)
		return (NULL);
	_memset((void *)new_header, 0, sizeof(list_t));
	new_header->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_header->str)
		{
			free(new_header);
			return (NULL);
		}
	}
	new_header->next = *head;
	*head = new_header;
	return (new_header);
}
/**
 * add_node_end - add a node at the end of the list
 * @head: header pointer of the list
 * @str: string to be put in the added node
 * @num: node index
 * Return: list header
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
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
 * print_list_str - prints the list
 * @h: header pointer
 * Return: size of the list
 */
size_t print_list_str(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}
/**
 * delete_node_at_index - deletes a certain node
 * @head: head pointer
 * @index: index
 * Return: 1 on success , 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *previous_node;
	unsigned int j = 0;

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
		if (i == index)
		{
			previous_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		j++;
		previous_node = node;
		node = node->next;
	}
	return (0);
}
/**
 * free_list - frees all list
 * @head_ptr: pointer to header
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

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

