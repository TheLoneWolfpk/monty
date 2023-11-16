#include "monty.h"

/**
 * f_stack - frees a doubly linked list
 * @head: head
 */
void f_stack(stack_t *head)
{
	stack_t *u;

	u = head;
	while (head)
	{
		u = head->next;
		free(head);
		head = u;
	}
}
