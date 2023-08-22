#include "monty.h"

int argError(void);
int file_openError(char *filename);

/**
 * argError - prints arguement error
 *
 * Return: EXT_FAILURE always
 */
int argError(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_openError - Prints file opening error
 * @filename: name of he file
 *
 * Return: EXIT_FAILURE
 */
int file_openError(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
