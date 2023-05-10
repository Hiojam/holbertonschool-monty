#include "monty.h"


stack_t *getStack(unsigned int position)
{
	stack_t **head = NULL;
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
	stack_t **head = NULL;
	stack_t *tmp;

	while ((*head))
	{
		tmp = (*head)->next;
		free(head);
		(*head) = tmp;
	}
}
