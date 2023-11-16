#include "monty.h"

/**
 * _pchar - prints the char at the top of stack
 * @head: head
 * @count: line number
 * Return: void
 */
void _pchar(stack_t **head, unsigned int count)
{
	stack_t *g;

	g = *head;
	if (!g)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (g->n > 127 || g->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of the range\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", g->n);
}
