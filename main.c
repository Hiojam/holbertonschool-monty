#include "monty.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		throwCustomError("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Check wether the file can be accessed and exit if not. */
	accessFile(argv[1]);

	/* Check instructions of the file. */
	/*checkInstructions(argv[1]);*/
	return (0);
}
