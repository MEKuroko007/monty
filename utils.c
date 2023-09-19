#include "monty.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: converted integer
 */
int _atoi(const char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] != '\0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (sign * result);
}
/**
 * _isdigit - checks if a string represents a number
 * @s: input string
 * Return: 1 if the string is a number
 */
int _isdigit(const char *s)
{
	unsigned int i = 0;


	if (s[0] == '\0')
		return (0);

	if (s[i] == '-')
		i++;

	for (; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}



/**
 * free_stack - Frees all elements of a stack.
 * @stack: Pointer to the head of the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
