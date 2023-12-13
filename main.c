#include "monty.h"

static int arg;
/**
 ** main - Entry
 ** @argc: argc
 ** @argv: argv
 ** Return: always 0
 **/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if(argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	readf(argv[1], &stack);

	if (!is_empty(stack))
		freestack(stack);
	
	return (0);
}

/**
 ** read - read file
 ** @fname: filename
 ** @stack: stack
 **
 ** Return: nothing
 **/
void readf(char *fname, stack_t **stack)
{
	size_t len = 0;
	ssize_t lread = 0;
	char *opcd = NULL, *line = NULL;
	int line_num = 1;
	fun func;
	FILE *file;

	file = fopen(fname, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}

	line = NULL;
	while ((lread = getline(&line, &len, file)) != -1)
	{
		opcd = parse(line_num, line);
		if (opcd == NULL || opcd[0] == '#')
		{
			line_num++;
			continue;
		}
		
		func = get_func(opcd);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcd);
			exit(EXIT_FAILURE);
		}

		func(stack, line_num);
		line_num++;
	}
	free(line);
	fclose(file);
}

/**
 ** parse - parse line
 ** @linenum: linenum
 ** @line: line
 **
 ** Return: opcd or NULL
 **/
char *parse(int linenum, char *line)
{
	char *opcd = NULL;
	char *argu = NULL;

	opcd = strtok(line, " \n");
	if (opcd == NULL)
		return (NULL);

	if (strcmp(opcd, "push") == 0)
	{
		argu = strtok(NULL, " \n");
		if (argu != NULL && is_num(argu))
		{
			arg = atoi(argu);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenum);
			exit(EXIT_FAILURE);
		}
	}
	return (opcd);
}

/**
 ** is_num - is a number
 ** @str: string
 **
 ** Return: 1 if number 0 if not
 **/
int is_num(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/**
 ** get_arg - return the arg variable
 ** Return: arg value
 **/
int get_arg(void)
{
	return (arg);
}
