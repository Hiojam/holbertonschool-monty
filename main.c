#include "monty.h"

stack_t **head = NULL;

int main(int argc, char const *argv[])
{
	char *fileName;

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
	checkInstructions(fileName);
	return (0);
}

void checkInstructions(char *fileName)
{
	FILE *f = fopen(fileName, "r");
	char *line;
	size_t len = 0, i = 1;
	int linesRead;
	char **arr;
	unsigned int val = 0;

	while ((linesRead = getline(&line, &len, f)) != -1)
	{
		arr = split_str(line, " ");
		printf("%s\n", arr[0]);

		val = arr[1] == NULL ? -1 : atoi(arr[1]);
		(void) val;
		
		/*ex_instruction(arr[0], i, val);*/
		i++;
	}

	fclose(f);
}
