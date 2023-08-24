#include "monty.h"

/**
 * _mul - multiplies two topmost elements
 * @head: top element
 * @line_number: line number
 * Return: no return
 */
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int i = 0;

	temp = *head;
	for (; temp != NULL; temp = temp->next, i++)
		;
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n *= (*head)->n;
	_pop(head, line_number);
}
