#include "monty.h"

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    /* Add more opcodes and functions as needed */
};

#define NUM_INSTRUCTIONS (sizeof(instructions) / sizeof(instruction_t))

int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    int line_number = 0;
    char line[100];
    char *opcode, *argument;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        line_number++;
        opcode = strtok(line, " \n");
        argument = strtok(NULL, " \n");

        int found = 0; // Flag to indicate if opcode was found

        for (size_t i = 0; i < NUM_INSTRUCTIONS; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number, argument);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            fprintf(stderr, "Error: L%d: Unknown instruction %s\n", line_number, opcode);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return (EXIT_SUCCESS);
}
