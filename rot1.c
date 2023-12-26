#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *current;

    /* Suppress unused warning */
    (void)line_number;

    /* Check if the stack is not empty and contains at least two elements */
    if (stack && *stack && (*stack)->next)
    {
        temp = *stack;
        *stack = temp->next;
        temp->next = NULL;

        /* Find the last element in the stack */
        current = *stack;
        while (current && current->next)
            current = current->next;

        /* Set the first element as the last one */
        if (current)
            current->next = temp;
    }
}
