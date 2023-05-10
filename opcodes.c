#include "monty.h"

void pushOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("Push");
}

void pallOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("pall");
}

void pintOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("pint");
}

void popOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("pop");
}

void swapOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("swap");
}

void addOpCode (stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("add");
}

void nopOpCode (stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("nop");
}
