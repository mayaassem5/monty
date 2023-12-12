#include "monty.h"
/**
 ** push - push
 ** @stack: struct
 ** @line_num: line
 **/
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *newnode;
	(void)line_number;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = globals.value;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack)
		stack->prev = newnode;
	*stack = newnode;
}
