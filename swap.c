#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!*stack || !((*stack)->next))
	{
	    fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	    exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;

	if (second->next)
        second->next->prev = first;

	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	
	*stack = second;
}
