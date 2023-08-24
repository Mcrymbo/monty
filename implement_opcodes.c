#include "monty.h"

/**
 * opcode_handle - handles opcodes
 * @op: opcode to compare
 * Return: no pointer to opcode function
 */
void (*opcode_handle(char *op))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"sub", _sub},
		{"div", _div},
		{NULL, NULL}
	};

	while (instruction[i].opcode != NULL)
	{
		if (strcmp(instruction[i].opcode, op) == 0)
			break;
		i++;
	}
	return (instruction[i].f);
}
