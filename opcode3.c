#include "monty.h"

/**
 * _rotl - rotates stack to top
 * @head: top node
 * @line_num: line number
 */
void _rotl(stack_t **head, unsigned int line_num)
{
	stack_t *temp1 = (*head)->next, *temp2 = *head;
	(void)line_num;

	if (!(*head) || !(*head)->next)
		return;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp2;
	temp1->prev = NULL;
	*head = temp1;
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
/**
 * _stack - implements stack
 * @head: top node
 * @line_num: line number
 */
void _stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	glob.type = 1;
}
/**
 * _queue - implement queue
 * @head: top node
 * @line_num: line number
 */
void _queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	glob.type = 0;
}
