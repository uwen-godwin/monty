#include "monty.h"
/**
 * get_instruction - Matches opcodes to their corresponding functions
 * @opcode: The opcode to match
 * @line_number: Line number in the Monty bytecode file
 * Return: A pointer to the corresponding instruction
 */
instruction_t *get_instruction(char *opcode, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div_op},
		{"mod", mod_op},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_op},
		{"queue", queue_op},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;
	char *token = strtok(opcode, " \t\n");

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(token, instructions[i].opcode) == 0)
		{
			instruction_t *result = malloc(sizeof(instruction_t));

			if (!result)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			memcpy(result, &instructions[i], sizeof(instruction_t));
			return (result);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
