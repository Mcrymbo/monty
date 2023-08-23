#include "monty.h"

/**
 * add_node_big - add node at geginning of a list
 * @head: pointer to first node
 * @value: value to add
 * Return: pointer to new node
 */
stack_t *add_node_big(stack_t **head, int value)
{
	stack_t *new, *temp = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return NULL;
	new->n = value;
	new->prev = NULL;
	if (temp != NULL)
	{
		while (temp->prev != NULL)
			temp = temp->prev;
		new->next = temp;
	}
	*head = new;
	return (new);
}

/**
 * add_node_end - add node at end of a doubly linked list
 * @head: pointer to leading node
 * @value: value to add
 * Return: pointer to new node
 */
stack_t *add_node_end(stack_t **head, int value)
{
	stack_t *new, *temp = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->next = NULL;
	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	new->prev = temp;
	return (new);
}
/**
 * print_node - prints all the elements in a doubly linked list
 * @head: pointer to first element in a doubly linked list
 */
size_t print_node(stack_t *head)
{
	size_t len = 0;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		len++;
	}
	return (len);
}
/**
 * free_list - frees the linked list
 * @head: pointer to head node
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;
	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
/**
 * free_glob - free global variable
 *
void free_glob(void)
{
	free_list(glob.head);
	free(glob.buffer);
	fclose(glob.fd);
}**/
