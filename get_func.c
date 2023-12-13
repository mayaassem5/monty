#include "monty.h"
/**
 ** get_func - get
 ** @opcd: opcd
 ** Return: get the op
 **/
fun get_func(char *opcd)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	while (op[i].f != NULL)
	{
		if (strcmp(opcd, op[i].opcode) == 0)
			return (op[i].f);
		i++;
	}
	return (NULL);
}

/**
 ** is_empty - check if the stack is empty
 ** @stack: stack
 **
 ** Return: 1 if empty, 0 if not
 **/
int is_empty(stack_t *stack)
{
		return (stack == NULL);
}

