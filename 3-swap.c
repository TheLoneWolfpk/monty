#include "monty.h"

/**
 * _swap - add to the top of stack
 * @head: stack head
 * @count: line number
 * Return: void
 */
void _swap(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	g = *head;
	u = g->n;
	g->n = g->next->n;
	g->next->n = u;
}
