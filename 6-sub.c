#include "monty.h"

/**
 * _sub - subtract
 * @head: head
 * @count: line number
 * Return: void
 */
void _sub(stack_t **head, unsigned int count)
{
	stack_t *u;
	int ss, nd;

	u = *head;
	for (nd = 0; u != NULL; nd++)
		u = u->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	u = *head;
	ss = u->next->n - u->n;
	u->next->n = ss;
	*head = u->next;
	free(u);
}
