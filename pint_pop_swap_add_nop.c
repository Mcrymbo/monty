#include "monty.h"

/**
 * _pint - prints value at top of track
 * @head: head of a doubly linked list
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!*stack)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "Can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - print and remove element from a stack
 * @head: pointer to top element
 * @line_num: line number
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
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
