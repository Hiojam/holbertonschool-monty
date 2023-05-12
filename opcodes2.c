#include "monty.h"

/**
 * addOpCode- adds the top two elements of the stack
 * @stack: stack head
 * @line_number: line num
 * Return: void
 **/

void addOpCode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	popOpCode(stack, line_number);
}

/**
 * nopOpCode - The opcode nop doesnt do anything.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 **/

void nopOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

