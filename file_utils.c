#include "monty.h"

/**
* accessFile - Checks wether a file is accessible or not
* @fileName: Name of the file to be checked.
* Return: 1 (Accessible), Exit (Error)
**/

unsigned int accessFile(char *fileName)
{
	FILE *f;

	if (!fileName)
	{
		throwCustomError("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(fileName, "r");

	if (!f)
	{
		throwCustomError("Error: Can't open file %s\n", fileName);
		free(fileName);
		exit(EXIT_FAILURE);
	}

	fclose(f);
	return (1);
}

