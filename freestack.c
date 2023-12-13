#include "monty.h"
/**
 ** freestack - free
 ** @stack: struct
 **
 **/
void freestack(stack_t **stack)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
		return;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->prev;
		free(tmp);
		tmp = NULL;
	}
}
