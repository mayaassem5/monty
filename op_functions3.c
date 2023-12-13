#include "monty.h"
/**
 ** mod - mod
 ** @stack: stack
 ** @line_num: line
 **
 **/
void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if(!(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack) = (*stack)->prev;
	(*stack)->n %= tmp->n;
	(*stack)->next = NULL;
	free(tmp);
}

/**
 ** pchar - print
 ** @stack: stack
 ** @line_num: line num
 ** Return: nothing
 **/
void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
