#include "monty.h"

/* ... (previous code) */

/**
 * get_front - Get the front of the queue
 * @stack: A pointer to the top of the queue
 *
 * Return: A pointer to the front of the queue
 */
stack_t *get_front(stack_t *stack)
{
    stack_t *current = stack;

    while (current && current->prev)
        current = current->prev;

    return current;
}
