#include "monty.h"

/**
 *selector - Function that selects and executes the correct function
 *@tokens: Pointer with array of comands
 *@head: Double linked list
 *@line_number: Number of line into the file
 */

void selector(char **tokens, stack_t **head, unsigned int line_number)
{
	instruction_t functions[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	int i = 0;

	if  (strcmp(tokens[0], "push") == 0)
	{
		push(tokens, head, line_number);
		return;
	}

	while (i < 2)
	{

		if ((strcmp((functions[i].opcode), tokens[0])) == 0)
		{
			functions[i].f(head, line_number);
			return;
		}
		i++;
	}

	if (strncmp(tokens[0], "#", 1) != 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, tokens[0]);
		exit(EXIT_FAILURE);
	}
}
