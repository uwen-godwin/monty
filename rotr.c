#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack && (*stack)->next)
    {
        stack_t *first = *stack;
        stack_t *last = *stack;

        while (last->next)
            last = last->next;

        *stack = last;
        last->prev->next = NULL;
        last->prev = NULL;
        (*stack)->next = first;
        first->prev = *stack;
    }
}
