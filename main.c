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
	char *line;
	size_t len = 0;
    unsigned int success = 1;
	int val;

	file_info.n_line = 1;
	while ((getline(&line, &len, file_info.f)) != -1)
	{
		val = 0;
		if (only_spaces(line) == 1)
		{
			file_info.n_line++;
			continue;
		}
		file_info.arr = split_str(line, " \n\t");
		if (file_info.arr == NULL)
		{
			file_info.n_line++;
			continue;
		}
		if (file_info.arr[1] && is_num(file_info.arr[1]))
			val = atoi(file_info.arr[1]);
		success = ex_instruction(file_info.arr[0], file_info.n_line, val, stack);
		if (!success)
		{
			throwCustomError("L%d: unknown instruction %s\n", file_info.n_line, file_info.arr[0]);
			free_all();
			exit(EXIT_FAILURE);
		}
		free_array(file_info.arr);
		file_info.n_line++;
	}
	fclose(file_info.f);
	free(line);
}
