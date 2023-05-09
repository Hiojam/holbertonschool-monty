#include "monty.h"

unsigned int ex_instruction(char *opCode, unsigned int line, int val)
{
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
	unsigned int i = 0;

	if (val != -1)
		addStack(val);

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opCode, instructions[i].opcode) == 0)
		{
			instructions[i].f(head, line);
			return (1);
		}
		i++;
	}
	return (0);
}