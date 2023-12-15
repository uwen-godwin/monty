#include "monty.h"

void push(stack_t **stack, unsigned int value) {
    stack_t *newNode = malloc(sizeof(stack_t));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    newNode->n = value;
    newNode->next = *stack;
    *stack = newNode;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}}
