#include "monty.h"

/**
 * _mul - multiplies the first 2 elements of the stack
 * @head: stack head
 * @count: line number
 * Return: void
 */
void _mul(stack_t **head, unsigned int count)
{
	stack_t *g;
	int len = 0, u;

	g = *head;
	while (g)
	{
		g = g->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	g = *head;
	u = g->next->n * g->n;
	g->next->n = u;
	*head = g->next;
	free(g);
}
