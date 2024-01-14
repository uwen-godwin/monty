#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>

#define STACK_MODE 0
#define QUEUE_MODE 1
#define STACK_SIZE 100
#define NUM_INSTRUCTIONS 20
#define MAX_LINE_LENGTH 1024
#define STACK_SIZE 100
#define MODE_STACK 0
#define MODE_QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct queue_s - Structure for queue mode
 * @front: Front of the queue
 * @rear: Rear of the queue
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct queue_s
{
    stack_t *front;
    stack_t *rear;
} queue_t;

typedef struct Monty {
    Node* top;
    Node* front;
    int mode;
} Monty;

/* Declare global_queue */
extern queue_t global_queue;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void comments(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack_op(stack_t **stack, unsigned int line_number);
void queue_op(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **stack, int value);
void reverse_stack(stack_t **stack);
/*void switchMode(stack_t **stack);*/
void execute(stack_t **stack, const char *command);

/* Helper functions */
instruction_t *get_instruction(char *opcode, unsigned int line_number);
void free_stack(stack_t **stack);
void switchMode(Monty *monty);

#endif /* MONTY_H */
