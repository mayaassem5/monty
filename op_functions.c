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

/**
 ** pint - pint
 ** @stack: struct
 ** @line_num: line
 **/
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	
	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

