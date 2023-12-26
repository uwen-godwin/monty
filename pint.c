#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
    /* Check if the stack is empty */
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Print the value at the top of the stack */
    printf("%d\n", (*stack)->n);
}
