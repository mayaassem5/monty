#include "monty.h"
/**
 ** push - push
 ** @stack: struct
 ** @line_num: line
 **/
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *newnode;
	(void)line_num;

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
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 ** pall - print all
 ** @stack: struct
 ** @line_num: line
 **/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void)line_num;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
