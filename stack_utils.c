#include "monty.h"

void addStack(unsigned int n)
{
	stack_t *element = malloc(sizeof(stack_t));

	if (element == NULL)
		return;

	element->n = n;
	element->next = NULL;
	element->prev = NULL;

	if (*head == NULL)
	{
		*head = element;
		return;
	}

	element->next = *head;
	*head = element;
	element->next->prev = element;
	return;
}

stack_t *getStack(unsigned int position)
{
	stack_t *node = malloc(sizeof(stack_t));
	unsigned int i = 0;

	if (node == NULL)
		return (NULL);

	for (; i < position; i++)
	{
		(*head) = (*head)->next;
		if ((*head) == NULL)
			return (NULL);
	}
	node = (*head);
	return (node);
}

void clearStack()
{
	stack_t *tmp;

	while ((*head))
	{
		tmp = (*head)->next;
		free(head);
		(*head) = tmp;
	}
}