#include "monty.h"

/**
 * getfunc - match the given opcode to its
 * corresponding function and execute it
 *
 * @opcode: opcode to be matched and executed
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Return: void
 */

void getfunc(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		/* Add more opcode-function mappings here */
		{NULL, NULL}};

	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
