#include "monty.h"

/**
 * _mul - multiplies two topmost elements
 * @head: top element
 * @line_number: line number
 * Return: no return
 */
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;
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
/**
 * _mod - computes modulus of two top elements
 * @stack: top node
 * @line_number: line  number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n %= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _pchar - prints character at top of stack
 * @head: pointer to first element of the stack
 * @line_num: line number
 */
void _pchar(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!head || !temp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
/**
 * _pstr - prints all string in the stack
 * @head: pointer to top element
 * @line_num: line number
 */
void _pstr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	(void)line_num;

	if (!head || !temp)
	{
		free_glob();
		printf("\n");
	}
	while (temp->n != 0 && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
