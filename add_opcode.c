#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_glob();
        exit(EXIT_FAILURE);
    }

    int num1, num2, sum;
    
    num1 = (*stack)->n;
    _pop(stack, line_number);  

    num2 = (*stack)->n;
    _pop(stack, line_number);

    sum = num1 + num2;

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation error\n");
        free_glob();
        exit(EXIT_FAILURE);
    }
    new_node->n = sum;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (!*stack)
    {
        *stack = new_node;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}
