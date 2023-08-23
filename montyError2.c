#include "monty.h"

int short_stack_error(unsigned int line_no, char *op);
int div_error(unsigned int line_no);
int pop_error(unsigned int line_no);
int div_error(unsigned int line_no);
int pchar_error(unsigned int line_no, char *message);

/**
 * pop_error - this prints out a pop error message for empty stacks.
 * @line_no: a line number in script where the error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_no)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
	return (EXIT_FAILURE);
}

/**
 * pint_error - it prints out a pint error message for empty stacks.
 * @line_no: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_no)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - This prints out a monty math function error message
 * for stacks and queues smaller than two nodes.
 * @line_no: Line number in Monty bytecodes file where the error have occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_no, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_no, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints out a division error message for a division by 0.
 * @line_no: is a line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_no)
{
	fprintf(stderr, "L%u: division by zero\n", line_no);
	return (EXIT_FAILURE);
}

/**
 * pchar_error -This prints the pchar error messages for empty stacks
 *  and none-character values.
 * @line_no: A Line number in Monty bytecodes file where A error occurred.
 * @message: error message to print out.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_no, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_no, message);
	return (EXIT_FAILURE);
}
