#include "monty.h"
#include <stdio.h>

/**
 * main - entry point
 * @argc: number of argument
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	size_t sz = 0;
	ssize_t rd_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	while (rd_line > 0)
	{
		char *cont = NULL;

		rd_line = getline(&cont, &sz, file);
		count++;

		if (rd_line > 0)
			execut(cont, &stack, count, file);

		free(cont);
	}

	f_stack(stack);
	fclose(file);

	return (0);
}

