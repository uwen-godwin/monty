#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current && current->n != 0 && (current->n >= 0 && current->n <= 127))
    {
        putchar((char)current->n);
        current = current->next;
    }
    putchar('\n');
}
