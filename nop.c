#include "monty.h"

/**
 * nop - Doesn't do anything
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    /* The nop opcode does nothing */
}
