#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t *instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		instruction = get_instruction(line, line_number);
		if (instruction)
			instruction->f(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, line);
			free_stack(&stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	if (fclose(file) == EOF)
	{
		fprintf(stderr, "Error: Can't close file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees all nodes in the stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current, *temp;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*stack = NULL;
}
