#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    /* Suppress unused warning */
    (void)line_number;

    /* Traverse the stack and print the string */
    while (current && current->n != 0 && current->n >= 32 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }

    putchar('\n');
}
