#include "monty.h"
/**
 ** add - add
 ** @stack: stack
 ** @line_num: line
 **
 **/
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack) = (*stack)->prev;
	(*stack)->n += tmp->n;
	(*stack)->next = NULL;
	free(tmp);
}

/**
 ** nop - nop
 ** @stack: struct
 ** @line_num: line
 **/
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
 ** sub - sub
 ** @stack: stack
 ** @line_num: line
 **
 **/
void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack) = (*stack)->prev;
	(*stack)->n -= tmp->n;
	(*stack)->next = NULL;
	free(tmp);
}
