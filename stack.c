#include "monty.h"

/**
 * reverse_stack - Reverses the order of elements in the stack
 * @stack: Pointer to the top of the stack
 */
void reverse_stack(stack_t **stack)
{
    stack_t *prev = NULL;
    stack_t *current = *stack;
    stack_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *stack = prev;
}
