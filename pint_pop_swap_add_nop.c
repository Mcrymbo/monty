#include "monty.h"

/**
 * _pint - prints value at top of track
 * @head: pointer to top node
 * @line_number: line number
 *
 */
void _pint(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	if (!*head)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * _pop - print and remove element from a stack
 * @head: pointer to top element
 * @line_num: line number
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * _swap - swaps two top most elements
 * @head: pointer to top element
 * @line_num: line number
 */
void _swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->prev = NULL;
	(*head)->next = temp;
}
/**
 * _nop - does nothing
 * @head: pointer to head
 * @line_nu: line number
 */
void _nop(stack_t **head, unsigned int line_nu)
{
	(void)head;
	(void)line_nu;
}
