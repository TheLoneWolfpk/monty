#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>

bus_w bus = {NULL, NULL, NULL, 0};

/**
 * main - entry point
 * @argc: number of argument
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t sz = 0;
	ssize_t rd_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rd_line > 0)
	{
		cont = NULL;
		rd_line = getline(&cont, &sz, file);
		bus.cont = cont;
		count++;
		if (rd_line > 0)
		execut(cont, &stack, count, file);
		free(cont);
	}
	f_stack(stack);
	fclose(file);
	return (0);
}
