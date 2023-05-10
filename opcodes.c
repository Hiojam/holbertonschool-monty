#include "monty.h"

void pushOpCode(stack_t **stack, unsigned int line_number)
{
    int n = (signed int)line_number;
    stack_t *element = malloc(sizeof(stack_t));

    printf("Entró a Push\n");
	if (element == NULL)
		throwCustomError("Malloc fail in push.");
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
	printf("Salió de Push\n");
}

void pallOpCode(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
    stack_t *aux = (*stack);

    printf("Entró a la función pall\n");
    while (aux)
    {
        printf("%d\n", aux->n);
        aux = aux->next;
    }
    printf("Salió de pall\n");
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
