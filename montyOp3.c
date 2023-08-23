#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_no);
void monty_pchar(stack_t **stack, unsigned int line_no);
void monty_pstr(stack_t **stack, unsigned int line_no);

/**
 * monty_nop - Does nothing
 * @stack: stack_t linked list.
 * @line_no: line number of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}

/**
 * monty_pchar - Prints the character in the top
 * @stack: stack_t linked list.
 * @line_no: line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_no, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_no,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the stack_t linked list.
 * @line_no: line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_no;
}
