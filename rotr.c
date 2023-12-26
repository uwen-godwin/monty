#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;

	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		current = *stack;
		while (current && current->next)
			current = current->next;
		temp = current;
		current = *stack;
		*stack = current->next;
		current->next = NULL;
		if (*stack)
			temp->next = current;
	}
}
