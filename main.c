#include "monty.h"

mode_t mode = STACK;

instruction_t opcodes[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {"sub", sub},
    {"div", div_op},
    {"mul", mul},
    {"mod", mod},
    {"comments", comments},
    {"pchar", pchar},
    {"pstr", pstr},
    {"rotl", rotl},
    {"rotr", rotr},
    {NULL, NULL}
};

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode = NULL;
    int value, i;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;

        opcode = malloc(strlen(line) + 1);
        if (opcode == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        if (sscanf(line, "%s %d", opcode, &value) == 2) {
            if (strcmp(opcode, "stack") == 0) {
                mode = STACK;
            } else if (strcmp(opcode, "queue") == 0) {
                mode = QUEUE;
            } else {
                for (i = 0; opcodes[i].opcode; i++) {
                    if (strcmp(opcode, opcodes[i].opcode) == 0) {
                        opcodes[i].f(&stack, line_number);
                        break;
                    }
                }
                if (!opcodes[i].opcode) {
                    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                    free(opcode);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
            }
        } else {
            fprintf(stderr, "L%d: invalid input format\n", line_number);
            free(opcode);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        free(opcode);
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error: Couldn't close file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
