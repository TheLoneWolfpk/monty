#include "monty.h"

/**
 * _div - divides the top two elements of the stack
 * @head: head
 * @count: line number
 * Return: void
 */
void _div(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack to short\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	g = *head;
	if (g->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = g->next->n / g->n;
	g->next->n = u;
	*head = g->next;
	free(g);
}
