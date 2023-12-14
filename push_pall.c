#include "monty.h"
/**
 * push - Pushes a value onto the stack.
 * @stack: Pointer to the stack.
 * @value: Value to be pushed onto the stack.
 * @line_number: Line number in the Monty file.
 */
void push(Stack *stack, int value, int line_number)
{
	if (stack->top == STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack->top++;
	stack->stack[stack->top] = value;
}
/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 */
void pall(Stack *stack)
{
	int i;

	for (i = stack->top; i >= 0; i--)
		printf("%d\n", stack->stack[i]);
}
/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	Stack stack;
	char line[100], opcode[10];
	int line_number = 0;
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}
	stack.top = -1;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';
		if (sscanf(line, "%s %d", opcode, &value) == 2)
		{
			if (strcmp(opcode, "push") == 0)
				push(&stack, value, line_number);
			else
			{
				fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
				return (EXIT_FAILURE);
			}
		}
		else if (strcmp(line, "pall") == 0)
			pall(&stack);
		else
		{
			fprintf(stderr, "L%d: Invalid instruction: %s\n", line_number, line);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
