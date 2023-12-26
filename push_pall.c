#include "monty.h"

/**
 * push - Pushes a new node with the given value to the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;

	token = strtok(NULL, " \t\n");

	if (!token || (!isdigit(*token) && *token != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
	push_stack(stack, value);
}
/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (!*stack)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
