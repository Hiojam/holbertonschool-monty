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

int deleteStack(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	tmp = *head;
	if (index == 0)
	{
		if (tmp->next)
			tmp->next->prev = NULL;
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	while ((i < index) && tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (tmp == NULL)
		return (-1);

	if (tmp->next)
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
	}
	else
		tmp->prev->next = NULL;

	free(tmp);
	return (1);
}
