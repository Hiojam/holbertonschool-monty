#include "monty.h"


int main(int argc, char const *argv[])
{
	char *fileName;
    stack_t *stack = NULL;

	if (argc < 2)
	{
		throwCustomError("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileName = strdup(argv[1]);

	if (!fileName)
	{
		throwCustomError("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	/* Check wether the file can be accessed and exit if not. */
	accessFile(fileName);

	/* Check instructions of the file. */
	checkInstructions(fileName, &stack);
	return (0);
}

void checkInstructions(char *fileName, stack_t **stack)
{
	FILE *f = fopen(fileName, "r");
	char *line;
	size_t len = 0;
    unsigned int i = 1;
	int linesRead;
	char **arr;
	int val = 0;

	while ((linesRead = getline(&line, &len, f)) != -1)
	{
		arr = split_str(line, " ");
		printf("arr[0]: %s\n", arr[0]);
        if (arr[1])
        {
            val = atoi(arr[1]);
            printf("arr[1]: %s\n", arr[1]);
            printf("val: %d\n", val);
        }
		ex_instruction(arr[0], i, val, stack);
		i++;
	}
	fclose(f);
}
