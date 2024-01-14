#include "monty.h"
#include <ctype.h>

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    int ascii_value;

    (void)line_number;

    while (current && current->n != 0 && (current->n >= 0 && current->n <= 127))
    {
        ascii_value = current->n;
        putchar(ascii_value);
        current = current->next;
    }
    putchar('\n');
}
