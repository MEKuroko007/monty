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
		second->prev = NULL;
	}
	else
	{
		;
	}
}
/**
 * rotr - rotates the stack to the bottom.
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		;
	}
	else
	{
		last = *stack;

		while (last->next)
		{
			last = last->next;
		}

		last->next = *stack;
		last->prev->next = NULL;
		last->prev = NULL;
		(*stack)->prev = last;
		(*stack) = last;
	}

}
