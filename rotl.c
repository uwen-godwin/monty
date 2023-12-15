#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack && (*stack)->next)
    {
        stack_t *first = *stack;
        stack_t *second = (*stack)->next;

        while (first->next)
            first = first->next;

        first->next = *stack;
        (*stack)->prev = first;

        *stack = second;
        (*stack)->prev = NULL;
        first->next = NULL;
    }
}
