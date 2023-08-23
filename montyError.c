#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknownError(char *opcode, unsigned int line_no);
int no_int_error(unsigned int line_no);

/**
 * usage_error - it prints out usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - it prints a file opening an error message with a file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknownError - this prints out an unknown instruction error message.
 * @opcode: Opcode shows where the error occurred.
 * @line_no: Line number on Monty bytecodes file where the error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknownError(char *opcode, unsigned int line_no)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_no, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - this prints outan invalid monty_push argument error message.
 * @line_no: Line number on Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_no)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_no);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - it prints out malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
