#include "monty.h"

/**
 * throwCustomError - Throws a custom error to stdout
 * @error: Contains the error string to be printed
 * Return: Void.
 **/
void throwCustomError(char *error, ...)
{
	va_list args;

	if (!error)
		error = "(null)";
	va_start(args, error);
	vfprintf(stderr, error, args);
	va_end(args);
}
/**
* free_all - Free Memory Dinamic
**/
void free_all(void)
{
	if (file_info.stack)
		free_stack(file_info.stack);
	if (file_info.file)
		free(file_info.file);
	if (file_info.arr)
		free_array(file_info.arr);
	if (file_info.line)
		free(file_info.line);
	fclose(file_info.f);
}

/**
 * free_stack - frees a dlistint_t list
 * @head: of a list
 **/
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
