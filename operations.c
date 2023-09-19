#include "monty.h"

/**
 * Execute_instruction : execute an opcode after read from the file
 *
 * @opcode: The opcode to execute.
 * @arg: The argument (if any) for the opcode.
 * @stack: Pointer to the stack.
 * @ln: Line number in the Monty file.
 * Return: 0 on success, 1 if the opcode is unknown.
 */


int operation(char *opcode, stack_t **stack, unsigned int ln)
{
    instruction_t opst[] = {
        {"pall", pall},
        {"pop", pop},
        {NULL, NULL}
    };

    int i = 0;

    while (opst[i].opcode) {
        if (strcmp(opcode, opst[i].opcode) == 0) {
                opst[i].f(stack, ln);
            
            return 0;
        }
        i++;
    }
    fprintf(stderr, "Unknown instruction: %s\n", opcode);
    return 1;
}


/**
 * push - add item to the stack
 * @stack: pointer to the stack
 * @arg: value to push
 * @line_number: line number in the file
 */

void push(stack_t **stack, unsigned int line_number, const char *arg)
{
    int value;
    stack_t *new_node;

    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push <int>\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (!_isdigit(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = _atoi(arg);
    new_node = malloc(sizeof(stack_t));

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

/*void pall(stack_t **stack)
{
    stack_t *temp;

    if (*stack == NULL)
        return;

    temp = *stack;
    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}*/



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



void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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
