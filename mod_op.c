#include "monty.h"

/**
 * mod_op - Computes the rest of the division of the second top element
 *           of the stack by the top element
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
    /* Check if the stack contains less than two elements */
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Check if the top element of the stack is zero */
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Compute the rest of the division of the second top element by the top element */
    (*stack)->next->n %= (*stack)->n;

    /* Pop the top element of the stack */
    pop(stack, line_number);
}
