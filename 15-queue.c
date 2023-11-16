#include "monty.h"

/**
 * _que - prints from the top
 * @head: head
 * @count: line number
 * Return: void
 */
void _que(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.l_fi = 1;
}

/**
 * a_que - add node to the tail
 * @n: new value
 * @head: head
 * Return: void
 */
void a_que(stack_t **head, int n)
{
	stack_t *n_nd, *u;

	u = *head;
	n_nd = malloc(sizeof(stack_t));
	if (n_nd == NULL)
		printf("Error\n");
	n_nd->n = n;
	n_nd->next = NULL;
	if (u)
	{
		while (u->next)
			u = u->next;
	}
	if (!u)
	{
		*head = n_nd;
		n_nd->prev = NULL;
	}
	else
	{
		u->next = n_nd;
		n_nd->prev = u;
	}
}
