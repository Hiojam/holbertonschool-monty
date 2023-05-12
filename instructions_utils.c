#include "monty.h"

unsigned int ex_instruction(char *opCode, unsigned int line, int val, stack_t **stack)
{

	unsigned int i = 0, n = (unsigned int) val;
	unsigned int i = 0;

	const instruction_t instructions[] = {
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
		pushOpCode(stack, val);
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
	else if (strcmp(arr[1], "0") != 0 && strcmp(arr[1], "-0") != 0)
	{
		return (-1);
	}
	return (0);
}

int is_num(char *arr)
{
	int i;

	for (i = 0; arr[i] != '\0'; i++)
	{
		if (isdigit(arr[i]) == 0)
		{
			if (i == 0)
			{
				if ((arr[0] != '-' && arr[0] != '+'))
					return (0);
				else
					continue;
			}
			return (0);
		}
	}
	return (1);
}

