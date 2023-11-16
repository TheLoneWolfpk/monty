#include "monty.h"

/**
 * _rotl - rotate stake at the top
 * @head: head
 * @count: line number
 * Return: void
 */
void _rotl(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *tmpo = *head, *u;

	if (*head == NULL || (*head)->next == NULL)
		return;
	u = (*head)->next;
	u->prev = NULL;

	while (tmpo->next != NULL)
		tmpo = tmpo->next;
	tmpo->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmpo;
	(*head) = u;
}
