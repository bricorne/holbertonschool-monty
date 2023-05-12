#include "monty.h"

/**
 * main - entry point of the Monty interpreter
 *
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t line_buf_size = 0;
	unsigned int line_number = 0;

	while (getline(&line, &line_buf_size, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;
		getfunc(opcode, &stack, line_number);
	}
	free(line);
	fclose(file);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
