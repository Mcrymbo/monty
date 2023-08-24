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
		fprintf(stderr, "L%u: Usage: push integer\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}

	while (glob.arg[i] != '\0')
	{
		if (!isdigit(glob.arg[i]) && glob.arg[i] != '-')
		{
			fprintf(stderr, "L%u: Usage: push integer\n", line_number);
			free_glob();
			exit(EXIT_FAILURE);
		}
		i++;
	}

	j = atoi(glob.arg);
	if (glob.type == 1)
		add_node_big(head, j);
	else
		add_node_end(head, j);
}

/**
 * _pall - prints values on a stack
 * @head: top of a stack
 * line_num: line number
 */
void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	(void)line_num;

	while(temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
