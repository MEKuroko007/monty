#include "monty.h"

/**
 * swap - swap the first and the second stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	*stack = second;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;
}
/**
 * add -  adds the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n += first->n;
	*stack = second;

	first->prev = NULL;
	first->next = NULL;
	free(first);
}
/**
 * nop - doesn’t do anything.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{

	(void) stack;
	(void) line_number;
}
/**
 * nop - doesn’t do anything.
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
 * div - doesn’t do anything.
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

