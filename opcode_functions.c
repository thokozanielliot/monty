#include "monty.h"

void _push(stack_t **doubly, unsigned int cline);
void _pall(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);

/**
 * _push - Push an element to the stack
 * @doubly: Doubly linked list
 * @cline: line number
 *
 * Return: No return
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!globv.arg)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "ussage: push integer\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	for (j = 0; globv.arg[j] != '\0'; j++)
	{
		if (!isdigit(globv.arg[j]) && globv.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", cline);
			fprintf(stderr, "usage: push integer\n");
			free_globv();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(globv.arg);
	if (globv.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - Prints all values on stack
 * @doubly: Doubly linked list
 * @cline: Line number
 *
 * Return: No return
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *new;
	(void)cline;

	new = *doubly;
	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * _pint - Print the value at the top of the stack
 * @doubly: Doubly linked list
 * @cline: Line number
 *
 * Return: No return
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "can't pint, stack empty\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - Remove top element of the stack
 * @doubly: Doubly  linked list
 * @cline: Line number
 *
 * Return: No return
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *new;

	if (doubly == NULL || *doubly == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", cline);
		free_globv();
		exit(EXIT_FAILURE);
	}
	new = *doubly;
	*doubly = (*doubly)->next;
	free(new);
}

/**
 * _swap - Swaps the top two elements of the stack
 * @doubly: Doubly linked list
 * @cline: Line number
 *
 * Return: No return
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *new = NULL;

	new = *doubly;
	for (; new != NULL; new = new->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", cline);
		free_globv();
		exit(EXIT_FAILURE);
	}
	new = *doubly;
	*doubly = (*doubly)->next;
	new->next = (*doubly)->next;
	new->prev = *doubly;
	(*doubly)->next = new;
	(*doubly)->prev = NULL;
}
