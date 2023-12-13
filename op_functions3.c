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

/**
 ** pstr - prints
 ** @stack: stack
 ** @line_num: line num
 ** Return: nothing
 **/
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	(void)line_num;
	if (tmp == NULL)
	{
		putchar('\n');
		return;
	}

	while (tmp && (tmp->n < 128 && tmp->n > 0))
	{
		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->prev;
	}
	putchar('\n');
}

/**
 ** rotl - print
 ** @stack: stack
 ** @line_num: line num
 ** Return: nothing
 **/
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL, *first = NULL;

	(void)line_num;

	if (*stack == NULL || (*stack)->prev == NULL)
		return;

	first = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	first->prev = NULL;
	first->next = NULL;
	tmp = *stack;

	while (tmp->prev != NULL)
		tmp = tmp->prev;

	tmp->prev = first;
	first->next = tmp;
}

/**
 ** rotr - prints
 ** @stack: stack
 ** @line_num: line num
 ** Return: nothing
 **/
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL, *first = *stack, *last = NULL;
	(void)line_num;

	if (*stack == NULL || (*stack)->prev == NULL)
		return;

	tmp = *stack;

	while (tmp->prev->prev != NULL)
		tmp = tmp->prev;

	last = tmp->prev;
	last->next = NULL;
	tmp->prev = NULL;
	last->prev = first;
	first->next = last;
	*stack = last;
}
