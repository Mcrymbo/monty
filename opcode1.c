#include "monty.h"

/**
 * _push - used to push elements to stack
 * @head: pointer to top element
 * @line_number: line number
 */
void _push(stack_t **head, unsigned int line_number)
{
	int i = 0, j;

	if (glob.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}

	while (glob.arg[i] != '\0')
	{
		if (!isdigit(glob.arg[i]) && glob.arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_glob();
			exit(EXIT_FAILURE);
		}
		i++;
	}

	j = atoi(glob.arg);
	if (glob.type == 1)
		add_node_big(head, j);
	else if (glob.type == 0)
		add_node_end(head, j);
}

/**
 * _pall - prints values on a stack
 * @head: top of a stack
 * @line_num: line number
 */
void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	(void)line_num;

	if (head == NULL)
		return;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _sub -subtracts top element from second top element
 * @head: pointer to top element
 * @line_num: line number
 */
void _sub(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;
	int i = 0;
	(void)line_num;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n -= (*head)->n;
	_pop(head, line_num);
}
/**
 * _div - divides second top element by topmost element
 * @head: pointer to top element
 * @line_num: line number
 */
void _div(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n /= (*head)->n;
	_pop(head, line_num);
}
