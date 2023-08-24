#include "monty.h"

void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);

/**
 * _nop - doesn't do anything
 * @doubly: Doubly linked list
 * @cline: Line number
 *
 * Retrun: No return
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _add - Add the top 2 elements of stack
 * @doubly: Doubly linked list
 * @cline: Line number
 * Return: No return
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int i = 0;
	stack_t *new = NULL;

	new = *doubly;
	for (; new != NULL; new = new->next, i++)
		;
	if (i < 2)
	{
		fprintf(stderr, "L%u: cant't add, stack too short\n", cline);
		free_globv();
		exit(EXIT_FAILURE);
	}
	new = (*doubly)->next;
	new->n += (*doubly)->n;
	_pop(doubly, cline);
}
