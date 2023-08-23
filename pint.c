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
