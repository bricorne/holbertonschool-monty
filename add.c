#include "monty.h"

/**
 * add_op - Adds the top two elements of the stack
 *
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode being executed
 */

void add_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	int sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

