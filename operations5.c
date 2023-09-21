#include "monty.h"

/**
 * check_push_args - Check if push argument is valid
 * @ln: Line number
 * @arg: Argument to validate
 * Return: The integer value if valid, or -1 on failure
 */
int check_push_args(unsigned int ln, const char *arg)
{
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	if (!_isdigit(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	return (_atoi(arg));
}

/**
 * push_stack - Push onto the stack
 * @stack: Pointer to the stack
 * @new_node: New node to push onto the stack
 */
void push_stack(stack_t **stack, stack_t *new_node)
{
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * push_queue - Push onto the queue
 * @stack: Pointer to the stack (queue)
 * @new_node: New node to push onto the queue
 */
void push_queue(stack_t **stack, stack_t *new_node)
{
	if (*stack == NULL)
	{
		*stack = new_node;
	} else
	{
		stack_t *current = *stack;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}
}

/**
 * _push - Push onto either stack or queue based on mode
 * @stack: Pointer to the stack
 * @ln: Line number
 * @arg: Argument to push
 * @mode: Mode (0 for stack, 1 for queue)
 */
void _push(stack_t **stack, unsigned int ln, const char *arg, int mode)
{
	int value = check_push_args(ln, arg);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (mode == 0)
	{
		push_stack(stack, new_node);
	} else if (mode == 1)
	{
		push_queue(stack, new_node);
	}
}
