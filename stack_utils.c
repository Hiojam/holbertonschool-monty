#include "monty.h"

/**
* clearStack - frees memory to each allocated element
**/
void clearStack(void)
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

/**
* deleteStack - removes an item from a doubly linked stack
* @head: pointer which represents the start the linked list
* @index: unsigned integer representing the index of the node
*/
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
