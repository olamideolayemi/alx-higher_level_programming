#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: hea of list
 * @n: integer to be added into listint_t list
 * Return: Address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nxt;

	nxt = malloc(sizeof(listint_t));
	if (nxt == NULL)
		return (NULL);
	nxt->n = n;
	nxt->next = *head;
	*head = nxt;

	return (nxt);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: The head of a list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *new_head = *head;
	listint_t *aux = NULL, *aux2 = NULL;

	if (*head == NULL || new_head->next == NULL)
		return (1);
	while (new_head != NULL)
	{
		add_nodeint(&aux, new_head->n);
		new_head = new_head->next;
	}
	aux2 = aux;
	while (*head != NULL)
	{
		if ((*head)->n != aux2->n)
		{
			free_listint(aux);
			return (0);
		}
		*head = (*head)->next;
		aux2 = aux2->next;
	}
	free_listint(aux);
	return (1);
}
