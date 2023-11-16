#include "monty.h"

/**
 * ad_node - add node to the head stack
 * @head: head
 * @n: new int
 * Return: void
 */
void ad_node(stack_t **head, int n)
{
	stack_t *n_nd, *u;

	u = *head;
	n_nd = malloc(sizeof(stack_t));
	if (n_nd == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (u)
		u->prev = n_nd;
	n_nd->n = n;
	n_nd->next = *head;
	n_nd->prev = NULL;
	*head = n_nd;
}
