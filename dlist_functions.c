#include "monty.h"

stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/**
 * add_dnodeint_end - Add node at the end of doubly linked list
 * @head: Doubly linked list
 * @n: Data
 * 
 * Return: Double linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *new;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error, malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	new = *head;
	while (new->next)
		new = new->next;
	tmp->next = new->next;
	tmp->prev = new;
	new->next = tmp;
	return (new->next);
}

/**
 * add_dnodeint - Add node at the begining of doubly linked list
 * @head: Doubly linked list
 * @n: Data
 *
 * Return: Doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlistint - Free doubly linked list
 * @head: Doubly linked list
 *
 * Return: No return
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
