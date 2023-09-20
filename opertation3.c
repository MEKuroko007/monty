#include "monty.h"
/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n -= first->n;
	*stack = second;

	first->prev = NULL;
	first->next = NULL;
	free(first);
}
/**
 * _div -  divides the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n /= first->n;
	*stack = second;

	first->prev = NULL;
	first->next = NULL;
	free(first);
}
/**
 * mul -  multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n *= first->n;
	*stack = second;

	first->prev = NULL;
	first->next = NULL;
	free(first);
}
/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n %= first->n;
	*stack = second;

	first->prev = NULL;
	first->next = NULL;
	free(first);
}
/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((char)ascii_value);
	putchar('\n');

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}


