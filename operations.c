#include "monty.h"

/**
 * operation - call functions
 * @opcode: The opcode to execute.
 * @stack: Pointer to the stack.
 * @ln:line number
 * Return: 0 on success, 1 if the opcode is unknown.
 */
void operation(char *opcode, stack_t **stack, unsigned int ln)
{
	instruction_t opst[] = {
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int i = 0;

	while (opst[i].opcode)
	{
		if (strcmp(opcode, opst[i].opcode) == 0)
		{
			opst[i].f(stack, ln);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
	fclose(file);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * pall - print the elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * pop - remove element from stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}



/**
 * pint - prints the value at the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/*---------------------------------------*/
