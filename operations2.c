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
 * _nop - doesn’t do anything.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void _nop(stack_t **stack, unsigned int line_number)
{

	(void) stack;
	(void) line_number;
}
