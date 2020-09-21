#include "monty.h"

/**
 *main - Main function for the interpreter Monty
 *@argc: Arguments counter
 *@argv: Arguments
 *Return: 0
 */

int main(int argc, char *argv[])
{
	unsigned int line_count = 0;
	FILE *fd;
	char *line_buf = NULL, **tokens = NULL;
	size_t line_buf_size = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line_buf, &line_buf_size, fd)) >= 0)
	{
		line_count++;
		tokens = split_line(line_buf);
		if (!tokens || !*tokens)
			continue;
		selector(tokens, &head, line_count);
		free(tokens);
	}

	free(line_buf);
	line_buf = NULL;
	fclose(fd);
	return (0);
}
