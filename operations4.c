#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * followed by a new line.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n != 0 && current->n >= 0
	&& current->n <= 127)
	{
		putchar((char)(current->n));
		current = current->next;
	}

	putchar('\n');
}
/**
 * rotl -  rotates the stack to the top.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *first = *stack;
		stack_t *second = (*stack)->next;
		stack_t *last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		first->next = NULL;
		first->prev = last;
		last->next = first;

		*stack = second;
		second->prev = NULL;
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

