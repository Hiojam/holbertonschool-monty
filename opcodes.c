#include "monty.h"

void pushOpCode(stack_t **stack, unsigned int line_number)
{
    int n = (signed int)line_number;
    stack_t *element = malloc(sizeof(stack_t));

	if (element == NULL)
	{
		throwCustomError("Malloc fail in push.");
		return;
	}

	element->n = n;
	element->prev = NULL;

	if (*stack == NULL)
	{
        element->next = NULL;
	}
    else
    {
        element->next = (*stack);
        (*stack)->prev = element;
    }
	*stack = element;
}

void pallOpCode(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
    stack_t *aux = (*stack);

    while (aux)
    {
        printf("%d\n", aux->n);
        aux = aux->next;
    }
}

void pintOpCode(stack_t **stack, unsigned int line_number)
{
	stack_t *st = malloc(sizeof(stack_t));

	if (!st)
	{
		throwCustomError("Error: malloc failed");
		return;
	}
	
	st = (*stack);

	if (!st)
	{
		printf("L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", st->n);
}

void popOpCode(stack_t **stack, unsigned int line_number)
{
	int resul = deleteStack(stack, 0);
	
	if (resul == -1)
	{
		printf("L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}	
}

void swapOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("swap");
}
