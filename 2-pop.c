#include "monty.h"

/**
 * _pop - prints the top
 * @head: head
 * @count: line number
 * Return: void
 */
void _pop(stack_t **head, unsigned int count)
{
	stack_t *g;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	g = *head;
	*head = g->next;
	free(g);
}
