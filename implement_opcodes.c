#include "monty.h"

/**
 * opcode_handle - handles opcodes
 * @opcode: opcode to compare
 * Return:
 */
void (*opcode_handle(char *op))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instruction[] = {
		{"pint", _pint},
		{NULL, NULL}
	};

	while (instruction[i].opcode != NULL)
	{
		if (_strcmp(instruction[i].opcode, op) == 0)
			break;
		i++;
	}
	return (instruction[i].f);
}
