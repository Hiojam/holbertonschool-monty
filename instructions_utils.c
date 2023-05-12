#include "monty.h"

int ex_instruction(char *oC, unsigned int l, int v, stack_t **s)
{
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

	if (strcmp("push", oC) == 0)
	{
		pushOpCode(s, v);
		return (1);
	}

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(oC, instructions[i].opcode) == 0)
		{
			instructions[i].f(s, l);
			return (1);
		}
		i++;
	}
	return (0);
}
/**
* chek_push_usage - Command checker
* @arr: array arrangement
*/
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
/**
* is_num - receives a string of characters
* @arr: array arrangement
*/
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
				continue;
			}
			return (0);
		}
	}
	return (1);
}

