#include "monty.h"

void pushOpCode(stack_t **stack, int val)
{
    int n = val;
    stack_t *element = malloc(sizeof(stack_t));

	if (element == NULL)
	{
		throwCustomError("Error: malloc failed\n");
		free(stack);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (n == 0)
	{
		if (chek_push_usage(file_info.arr) != 0)
		{
			throwCustomError("L%d: usage: push integer\n", file_info.n_line);
			free_all();
			exit(EXIT_FAILURE);
		}
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
		throwCustomError("Error: malloc failed\n");
		return;
	}
	
	st = (*stack);

	if (!st)
	{
		throwCustomError("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", st->n);
}

void popOpCode(stack_t **stack, unsigned int line_number)
{
	int resul = deleteStack(stack, 0);
	
	if (resul == -1)
	{
		throwCustomError("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}	
}

void swapOpCode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("swap");
}
