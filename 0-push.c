#include "monty.h"

/**
 * _push - add to stack
 * @head: head
 * @count: line number
 * Return: void
 */
void _push(stack_t **head, unsigned int count)
{
	int n, y = 0, fl = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			y++;
		for (; bus.arg[y] != '\0'; y++)
		{
			if (bus.arg[y] > 57 || bus.arg[y] < 48)
				fl = 1;
		}
		if (fl == 1)
		{
			fprintf(stderr, "L%d: usuage: push integer\n", count);
			fclose(bus.file);
			free(bus.cont);
			f_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usuage: push integer\n", count);
		fclose(bus.file);
		free(bus.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.l_fi == 0)
		ad_node(head, n);
	else
		_que(head, n);
}
