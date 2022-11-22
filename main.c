#include "monty.h"

char **GlobalVar;

/**
 * main - Entry point
 * @argc: argumnt  count
 * @argv: array of input arg strings
 * Return: Always 0 on completion, otherwise 1 on exit fail
 */
int main(int argc, char *argv[])
{
	stack_t *dasStack = NULL;
	unsigned int lineNum = 0;
	FILE *inboundFD = NULL;
	size_t n = 0;
	char *line, *first, *second;
	const char delims[] = " \t\n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inboundFD = fopen(argv[1], "r");
	if (!(inboundFD))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	GlobalVar = malloc(sizeof(char *) * 2);
	if (!GlobalVar)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, inboundFD) != -1)
	{
		lineNum++;
		first = strtok(line, delims);
		if (!first || first[0] == '#')
			continue;
		second = strtok(NULL, delims);
		GlobalVar[0] = first;
		GlobalVar[1] = second;
		op_fun_res(lineNum, first, &dasStack);
	}
	free_sg(&dasStack);
	fclose(inboundFD);
	return (0);
}
