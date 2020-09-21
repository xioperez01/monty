#include "monty.h"
#define BUFF_SIZE 128

/**
 *split_line - Function that converts the read line to token
 *@line: Line read
 *Return: array with line commands
 */

char **split_line(char *line)
{
	char *parsed, **commands;
	int index = 0;

	if (line == NULL)
		return (NULL);

	commands = malloc(BUFF_SIZE * sizeof(char *));

	if (commands == NULL)
		return (NULL);

	parsed = strtok(line, " \n\t\r");

	while (parsed != NULL)
	{
		commands[index] = parsed;
		index++;
		parsed = strtok(NULL, "\n\t\a\r ;:");
	}

	commands[index] = NULL;
	return (commands);
}
