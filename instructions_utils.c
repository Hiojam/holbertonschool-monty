#include "monty.h"

unsigned int ex_instruction(char *opCode, unsigned int line, int val, stack_t **stack)
{
    (void)line;
    (void)val;
    unsigned int i = 0, n = (unsigned int)val;
	instruction_t instructions[] = {
		{"push", pushOpCode},
		{"pall", pallOpCode},
		{"pint", pintOpCode},
		{"pop", popOpCode},
		{"swap", swapOpCode},
		{"add", addOpCode},
		{"nop", nopOpCode},
		{NULL, NULL}
	};

    printf("Entró a ejecutar\n");
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opCode, instructions[i].opcode) == 0)
		{
            if (strcmp("push", opCode) == 0)
            {
                printf("push\n");
                instructions[i].f(stack, n);
                return (1);
            }
            printf("No push\n");
			instructions[i].f(stack, line);
			return (1);
		}
		i++;
	}
	return (0);
}
