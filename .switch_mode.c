#include "monty.h"

void switchMode(void) {
    Node* prev = NULL;
    Node* current;
    Node* next;

    if (monty->mode == STACK_MODE) {
        current = monty->top;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        monty->front = prev;
        monty->mode = QUEUE_MODE;
    } else {
        current = monty->front;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        monty->top = prev;
        monty->mode = STACK_MODE;
    }
}
