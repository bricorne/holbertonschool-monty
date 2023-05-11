#include "monty.h"

/*
 *
 *
 *
 *
 */

int main(int argc, char **argv)
{
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
	return EXIT_SUCCESS;
}
