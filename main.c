#include "monty.h"

file_t file_info;

/**
 * 
*/
int main(int argc, char const *argv[])
{
    stack_t *stack = NULL;

	if (argc < 2)
	{
		throwCustomError("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_info.file = strdup(argv[1]);

	if (!file_info.file)
	{
		throwCustomError("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	/* Check wether the file can be accessed and exit if not. */
	accessFile(file_info.file);

	/* Check instructions of the file. */
	checkInstructions(file_info.file, &stack);
	return (0);
}

void checkInstructions(char *fileName, stack_t **stack)
{
	file_info.f = fopen(fileName, "r");
	char *line, **arr;
	size_t len = 0;
    unsigned int success = 1;
	int val;

	file_info.n_line = 1;
	while ((getline(&line, &len, file_info.f)) != -1)
	{
		val = 0;
		if (only_spaces(line) == 1)
			continue;
		arr = split_str(line, " \n\t");
		if (arr == NULL)
			continue;
		if (arr[1])
			val = atoi(arr[1]);
		if (val == 0)
		{
			if (chek_push_usage(arr) != 0)
			{
				throwCustomError("L%d: usage: push integer\n", file_info.n_line);
				free_all(char *line, char **arr);
				exit(EXIT_FAILURE);
			}
		} 
		success = ex_instruction(arr[0], file_info.n_line, val, stack);
		if (!success)
		{
			throwCustomError("L%d: unknown instruction %s\n", file_info.n_line, arr[0]);
			void free_all(char *line, char **arr);
			exit(EXIT_FAILURE);
		}
		free_array(arr);
		file_info.n_line++;
	}
	fclose(file_info.f);
	free(line);
}
