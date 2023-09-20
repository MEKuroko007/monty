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

	if ((stack == NULL) || (*stack == NULL))
	{
		printf("\n");
	}

	while (current != NULL && current->n != 0 && current->n >= 0
	&& current->n <= 127)
	{
		printf("%c", (current->n));
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	stack_t *last;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		second = (*stack)->next;
		last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		first->next = NULL;
		first->prev = last;
		last->next = first;

		*stack = second;
		if (second != NULL)
		{
			second->prev = NULL;
		}
	}
	else
	{
		;
	}
}
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	last = *stack;
	second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

