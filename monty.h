#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * 
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variable -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @cont: line content
 * @l_fi: flag change stack <-> queue
 * Description: carries value through the program
 */
typedef struct bus_v
{
	char *arg;
	FILE *file;
	char *cont;
	int l_fi;
} bus_w;

extern bus_w bus;

char *_realloc(char *ptr, unsigned int ol_sz, unsigned int n_sz);
ssize_t gstdin(char **l_ptr, int fl);
char *c_line(char cont);

void _push(stack_t **head, unsigned int count);
void _pall(stack_t **head, unsigned int count);
void _pint(stack_t **haed, unsigned int count);

int execut(char *cont, stack_t **head, unsigned int count, FILE *file);
void f_stack(stack_t *head);

void _pop(stack_t **head, unsigned int count);
void _swap(stack_t **head, unsigned int count);
void _add(stack_t **head, unsigned int count);
void _nop(stack_t **head, unsigned int count);
void _sub(stack_t **head, unsigned int count);
void _div(stack_t **head, unsigned int count);
void _mul(stack_t **head, unsigned int count);
void _mod(stack_t **head, unsigned int count);
void _pchar(stack_t **head, unsigned int count);
void _pstr(stack_t **head, unsigned int count);
void _rotl(stack_t **head, unsigned int count);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int count);

void ad_node(stack_t **head, int n);
void ad_que(stack_t **head, int n);
void _que(stack_t **head, unsigned int count);
void _stack(stack_t **head, unsigned int count);

#endif /* MONTY_H */
