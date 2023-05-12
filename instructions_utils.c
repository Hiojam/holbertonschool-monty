#include "monty.h"

/**
 * ex_instruction - Executes an specific instruction if found.
 *
 * @oC: The opCode to search for.
 * @l: The line number.
 * @v: The parameter value. Default is 0.
 * @s: The stack.
 *
 * Return: 1 on Success, 0 on Error.
*/
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
 * check_push_usage - Checks wether the push opCode can be used.
 *
 * @arr: The array containing args.
 * Return: 0 on Success, -1 on Error.
*/
int check_push_usage(char **arr)
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
 * is_num - Checks if the arr values are a number.
 *
 * @arr: The array to check from.
 * Return: 1 on Success, 0 on Error.
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

