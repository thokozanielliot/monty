#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_no);
void monty_pall(stack_t **stack, unsigned int line_no);
void monty_pint(stack_t **stack, unsigned int line_no);
void monty_pop(stack_t **stack, unsigned int line_no);
void monty_swap(stack_t **stack, unsigned int line_no);

/**
 * monty_push - This pushes a value to the stack_t linked list.
 * @stack: pointer to the top mode node of the stack_t linked list.
 * @line_no: This is he current working line number of the Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp, *new;
	int w;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_no));
		return;
	}

	for (w = 0; op_toks[1][w]; w++)
	{
		if (op_toks[1][w] == '-' && w == 0)
			continue;
		if (op_toks[1][w] < '0' || op_toks[1][w] > '9')
		{
			set_op_tok_error(no_int_error(line_no));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * monty_pall - It prints the values of the stack_t linked list.
 * @stack: The pointer to top mode node of the stack_t linked list.
 * @line_no: current working line number of the Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_no;
}

/**
 * monty_pint - it prints out the top value of the stack_t linked list.
 * @stack: pointer to the top mode node of the stack_t linked list.
 * @line_no: current working line number of the Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_no));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - this deletes the top value element of the stack_t linked list.
 * @stack: the pointer to top mode node of stack_t linked list.
 * @line_no: current working line number of Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_no)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_no));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - it swaps top two value elements of stack_t linked list.
 * @stack: pointer to top mode node of stack_t linked list.
 * @line_no: current working line number of Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_no, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

