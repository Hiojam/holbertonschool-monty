#include "monty.h"

/**
 * throwCustomError - Throws a custom error to stdout.
 * 
 * @error: Contains the error string to be printed.
 * 
 * Return: Void.
*/
void throwCustomError(char *error, ...)
{
	va_list args;

	if (!error)
		error = "(null)";

	va_start(args, error);

	vfprintf(stderr, error, args);

	va_end(args);
}

void free_all(char *line, char **arr)
{
	free_array(arr);
	free(line);
	fclose(file_info.f);
}