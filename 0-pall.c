#include "monty.h"

/**
 * _pall - print the stack
 * @head: stack head
 * @count: no used
 * Return: void
 */
void _pall(stack_t **head, unsigned int count)
{
	stack_t *g;
	(void)count;

	g = *head;
	if (g == NULL)
		return;
	while (g)
	{
		printf("%d\n", g->n);
		g = g->next;
	}
}
