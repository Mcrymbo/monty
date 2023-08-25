#include "monty.h"

/**
 * _rotl - rotates stack to top
 * @head: top node
 * @line_num: line number
 */
void _rotl(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head, *temp2 = (*head)->next;
	(void)line_num;

	if (!head || !temp)
		return;
	while (temp->next)
		temp = temp->next;
	temp2->prev = NULL;
	temp->next = *head;
	(*head)->prev = temp;
	(*head)->next = NULL;
	*head = temp2;
}

