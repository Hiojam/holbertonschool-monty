#include "monty.h"

/**
 * tokenize - splits a string and returns an array of each word of the string.
 * @line: string to tokenize
 *
 * Return: An array of strings representing the split input
 */
char **tokenize(char *line)
{
	char *line_cpy = NULL, *token = NULL, *delim = " \t\n", **args = NULL;
	int n_args = 0, i = 0;

	line_cpy = strdup(line);
	if (!line_cpy)
	{
		throwCustomError("Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	token = strtok(line_cpy, delim);
	while (token)
		n_args++, token = strtok(NULL, delim);
	free(line_cpy);
	n_args++;
	args = malloc(sizeof(char *) * n_args);
	if (!args)
	{
		throwCustomError("Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	for (i = 0; i < n_args - 1 && token != NULL; i++)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			while (--i >= 0)
				free(args[i]);
			throwCustomError("Error: malloc failed\n");
			free_all();
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_array- Frees an array.
 * @arr: Array to be freed.
 **/
void free_array(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	for (; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

/**
 * only_spaces - check for a line with only spaces
 * @line: to check
 * Return: 0 or 1
 **/
int only_spaces(char *line)
{
	int o_spaces = 1;
	size_t i;

	for (i = 0; i < (strlen(line) - 1); i++)
	{
		if (line[i] != 9 && line[i] != 32)
			o_spaces = 0;
	}
	return (o_spaces);
}
