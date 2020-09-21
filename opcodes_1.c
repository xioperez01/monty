#include "monty.h"

/**
 *is_digit - Function that verifies if a string is an integer
 *@n: string to check
 *Return: 1 if it is an integer or 0 if it is not
 */

int is_digit(const char *n)
{
	int i = 0;

	if (n[i] == '-')
		i = 1;
	for (; n[i] != '\0'; i++)
	{
		if (isdigit(n[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 *push - Function that pushes an element to the stack.
 *@tokens: Command line
 *@head: Double linkend lsit
 *@line_number: bytecode line number
 */

void push(char **tokens, stack_t **head, unsigned int line_number)
{
	if (head == NULL)
		return;

	if ((is_digit(tokens[1]) == 0) || tokens[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((add_dnodeint(head, atoi(tokens[1]))) == NULL)
		{
			free_dlistint(*head);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 *pall - prints all the values on the stack,
 *starting from the top of the stack.
 *@stack: Double linkend lsit
 *@line_number: bytecode line number
 */

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
		return;

	print_dlistint(*stack);
}

/**
 *pint - Function that prints the value at the top of the stack
 *@stack: Double linkend lsit
 *@line_number: bytecode line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
