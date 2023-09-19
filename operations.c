#include "monty.h"



/**
 * push - add item to the stack
 * @stack: pointer to the stack
 * @arg: value to push
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
    if (!is_valid_integer(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = _atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * pall - print the elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void pall(stack_t **stack, unsigned int line_number, const char *arg)
{
    (void)line_number;
	(void)arg;

    while (*stack != NULL)
    {
        printf("%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }
}