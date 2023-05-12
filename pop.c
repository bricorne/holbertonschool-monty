#include "monty.h"

/**
 * pop_op - Removes the top element from the stack
 * 
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

