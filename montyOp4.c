#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_no);
void monty_rotr(stack_t **stack, unsigned int line_no);
void monty_stack(stack_t **stack, unsigned int line_no);
void monty_queue(stack_t **stack, unsigned int line_no);

/**
 * monty_rotl - Rotates the value of a stack_t linked list to the bottom.
 * @stack: stack_t linked list.
 * @line_no: line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_no;
}

/**
 * monty_rotr - Rotates the value of a stack_t linked list to the top.
 * @stack: stack_t linked list.
 * @line_no: line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_no;
}

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: stack_t linked list.
 * @line_no: line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_no)
{
	(*stack)->n = STACK;
	(void)line_no;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: stack_t linked list.
 * @line_no: line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_no)
{
	(*stack)->n = QUEUE;
	(void)line_no;
}
