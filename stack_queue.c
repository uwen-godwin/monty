#include "monty.h"

/**
 * stack_op - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
    /* Suppress unused warning */
    (void)line_number;

    /* Unused parameter */
    (void)stack;

    /* No action needed for stack, as it is the default behavior */
}

/**
 * queue_op - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
    /* Suppress unused warning */
    (void)line_number;

    /* Unused parameter */
    (void)stack;
}
