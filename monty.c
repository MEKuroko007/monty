#include "monty.h"

/**
 * main - Entry point for Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	unsigned int line_number = 0;
	char line[100];
	int result;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	while (fgets(line, sizeof(line), file))
	{
		char *opcode = strtok(line, " \n\t");
		char *argument = strtok(NULL, " \n\t");

		if (opcode == NULL)
		{ continue; }
		if (strcmp(opcode, "push") == 0)
		{	 _push(&stack, line_number, argument); }
		else
		{
		result = operation(opcode, &stack, line_number);
		if (result == 1)
		{   /*fclose(file);*/
			free_stack(&stack);
			exit(EXIT_FAILURE); } }
		line_number++;
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}
