#include "monty.h"

file_t file_info;
int main(int argc, char const *argv[])
{
	file_info.stack = NULL;
	if (argc != 2)
	{
		throwCustomError("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_info.file = strdup(argv[1]);
	if (!file_info.file)
	{
		throwCustomError("Error: malloc failed");
		free_all();
		exit(EXIT_FAILURE);
	}
	accessFile(file_info.file);
	checkInstructions(file_info.file, &file_info.stack);
	return (0);
}

void checkInstructions(char *fileName, stack_t **stack)
{
	size_t len = 0;
	int val, nReads, success = 1;
	file_info.f = fopen(fileName, "r");
	file_info.n_line = 1;
	while ((nReads = getline(&file_info.line, &len, file_info.f)) != -1)
	{
		if (nReads == -1)
		{
			throwCustomError("Error: malloc failed");
			free_all();
			exit(EXIT_FAILURE);
		}
		val = 0;
		if (only_spaces(file_info.line) == 1)
		{
			file_info.n_line++;
			continue;
		}
		file_info.arr = tokenize(file_info.line);
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
			throwCustomError("L%d: unknown instruction %s\n",
					 file_info.n_line, file_info.arr[0]);
			free_all();
			exit(EXIT_FAILURE);
		}
		free_array(file_info.arr);
		file_info.arr = NULL;
		file_info.n_line++;
	}
	free_all();
}
