#include "monty.h"

unsigned int ex_instruction(char *opCode, unsigned int line, int val, stack_t **stack)
{
unsigned int i = 0, n = (unsigned int) val;

	const instruction_t instructions[] = {
		{"push", pushOpCode},
		{"pall", pallOpCode},
		{"pint", pintOpCode},
		{"pop", popOpCode},
		{"swap", swapOpCode},
		{"add", addOpCode},
		{"nop", nopOpCode},
		{NULL, NULL}
	};

	if (strcmp("push", opCode) == 0)
	{
		pushOpCode(stack, n);
		return (1);
	}

	while (instructions[i].opcode != NULL)
	{

		if (strcmp(opCode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line);
			return (1);
		}
		i++;
	}
	return (0);
}

int chek_push_usage(char **arr)
{
	if (!arr[1])
	{
		return (-1);
	}
	else if (strcmp(arr[0], "0") != 0)
	{
		return (-1);
	}
	return (0);
}
