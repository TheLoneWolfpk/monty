#include "monty.h"

/**
 * _pstr - prints the string starting from the top
 * @head: head
 * @count: line number
 * Return: void
 */
void _pstr(stack_t **head, unsigned int count)
{
	stack_t *g;
	(void)count;

	g = *head;
	while (g)
	{
		if (g->n > 127 || g->n <= 0)
			break;
		printf("%c", g->n);
		g = g->next;
	}
	printf("\n");
}
