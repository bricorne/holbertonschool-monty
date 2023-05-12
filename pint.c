#include "monty.h"

/**
 * pint_op - Prints the value at the top of the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
