#include "monty.h"

/**
 ** main - Entry
 ** @argc: argc
 ** @argv: argv
 ** Return: always 0
 **/
global_vars_t globals;

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_num = 0;
	stack_t *stack = NULL;

	if(argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if(file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while((read = getline(&line, &len, file)) != -1)
	{
		line_num++;
		process(line, line_num, &stack);

	}

	free(line);
	fclose(file);
	freestack(stack);
	return (EXIT_SUCESS);
}

/**
 ** process - process
 ** @line: line
 ** @line_num: line num
 ** @stack: data structure
 **/
void process(char *line, unsigned int line_num, stack_t **stack)
{
	char *opcd = NULL, *arg = NULL;
	void (*func)(stack_t **, unsigned int);

	opcd = strtok(line, " \n\t");
	if (opcd == NULL ||opcd[0] == "#")
		return;

	if (strcmp(opcd, "push") == 0)
	{
		arg = strtok(NULL, " \n\t");
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free(line);
			freestack(*stack);
			exit(EXIT_FAILURE);
		}
		globals.value = atoi(arg);
	}
	func = get_func(opcd);
	if (func != NULL)
		func(stack, line_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcd);
		free(line);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
}

