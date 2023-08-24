#include "monty.h"

/**
 *add_node_end - adding node at end of a list
 *@head: index to head node
 *@n: data to add
 *Return: new node
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new, *temp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	new->next = temp->next;
	new->prev = temp;
	new->next = new;
	return (temp->next);
}

/**
 *add_node_big - add to top element of a stack
 *@head: index to top node
 *@n: data to store
 *Return: new node
 */
stack_t *add_node_big(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	(*head)->prev = new;
	new->next = (*head);
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
