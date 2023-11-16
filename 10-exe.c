#include "monty.h"

/**
 * execut - executes the opcode
 * @stack: head of linked list
 * @count: line counter
 * @file: pointer to monty file
 * @cont: content of line
 * Return: void
 */
int execut(char *cont, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"div", _div}, {"sub", _sub},
		{"mul", _mul}, {"pchar", _pchar}, {"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr}, {"queue", _que}, {"stack", _stack}, {NULL, NULL}
	};
	unsigned int x = 0;
	char *ope;

	ope = strtok(cont, " \n\t");
	if (ope && ope[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[x].opcode && ope)
	{
		if (strcmp(ope, opst[x].opcode) == 0)
		{
			opst[x].f(stack, count);
			return (0);
		}
		x++;
	}
	if (ope && opst[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, ope);
		fclose(file);
		free(cont);
		f_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
