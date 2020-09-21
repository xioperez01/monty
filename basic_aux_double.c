#include "monty.h"

/**
 *print_dlistint - function that prints all the elements of a dlistint_t list
 *@h: Doubly linked list
 */

void print_dlistint(stack_t *h)
{
	while (h && h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 *add_dnodeint - function that adds a new node at the beginning of a
 *dlistint_t list.
 *@head: Head of the linkend list
 *@n: Node content
 *Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}

/**
 *free_dlistint - function that free a dlistint_t list.
 *@head: Linked list
 *Return: Void
 */

void free_dlistint(stack_t *head)
{
	if (!head)
		return;

	while (head && head->next)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
