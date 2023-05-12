#include "monty.h"

/**
 * pall_op - print all the values on the stack
 *
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 *
 * Return: void
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
