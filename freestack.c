#include "monty.h"
/**
 ** freestack - free
 ** @stack: struct
 **
 **/
void freestack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
