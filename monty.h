#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>

/**
 ** struct stack_s - doubly linked list representation of a stack (or queue)
 ** @n: integer
 ** @prev: points to the previous element of the stack (or queue)
 ** @next: points to the next element of the stack (or queue)
 **
 ** Description: doubly linked list node structure
 ** for stack, queues, LIFO, FIFO
 **/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 ** struct global_vars_s - global variables
 ** @value: integer
 ** @stack: struct
 **
 ** Description: global var
 ** for stack, queues, LIFO, FIFO
 **/
typedef struct global_vars_s
{
	stack_t *stack;
	int value;
} global_vars_t;

extern global_vars_t globals;

/**
 ** struct instruction_s - opcode and its function
 ** @opcode: the opcode
 ** @f: function to handle the opcode
 **
 ** Description: opcode and its function
 ** for stack, queues, LIFO, FIFO
 **/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void freestack(stack_t *stack);
void(*get_func(char *opcd))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void process(char *line, unsigned int line_num, stack_t **stack);

#endif
