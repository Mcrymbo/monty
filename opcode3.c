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

	if (*head == NULL || (*head)->next == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	temp2->prev = NULL;
	temp->next = *head;
	(*head)->prev = temp;
	(*head)->next = NULL;
	*head = temp2;
}
/**
 * _rotr - reverses the stack
 * @head: top node
 * @line_num: line number
 */
void _rotr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	(void)line_num;

	if (!(*head) || !(*head)->next)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
}
