#include "monty.h"
/**
 ** get_func - get
 ** @opcd: opcd
 ** Return: get the op
 **/
void (*get_func(char *opcd))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	while (op[i].opcode != NULL)
	{
		if (strcmp(opcd, op[i].opcode) == 0)
			return (op[i].f);
	}
	return (NULL);
}
