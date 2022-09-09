#include "monty.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: argument vector.
 *
 * Return: Nothing
 */
int main(int argc, char *argv[])
{	
	FILE *file;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (1);
}
