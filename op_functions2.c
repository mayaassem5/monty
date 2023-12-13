#include "monty.h"
/**
 ** add - add
 ** @stack: stack
 ** @line_num: line
 **
 **/
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n += temp->n;
	(*stack)->prev = temp->prev;
	free(temp);
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

