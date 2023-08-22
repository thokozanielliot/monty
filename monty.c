#include "monty.h"

int main(int ac, char **av);
int runMonty(FILE *monty_file);

/**
 * main - eEntry point of the Monty Byte Interpreter
 * @ac: arguement number
 * @av: arguement vector
 *
 * Return: on SUCCESS EXIT_SUCCESS
 * Otherwise EXIT_FAILURE
 */
int main(int ac, char **av)
{
	FILE *monty_file = NULL;
	int exit_code = EXIT_SUCCESS;

	if (ac != 2)
	{
		/* exit interpreter: print 'Usage: monty file' */
		exit_code =  argError();
		return (exit_code);
	}
	monty_file = fopen(av[1], "r");
	if (monty_file == NULL)
	{
		/* file opening error */
		exit_code = file_openError(av[1]);
		return (exit_code);
	}
	exit_code = runMonty(monty_file);
	fclose(monty_file);
	return (exit_code);
}

/**
 * runMonty - Executing Monty byte code
 * @monty_file: File for Monty Script
 *
 * Return: Exit_SUCCES on SUCCESS
 * otherwise EXIT_FAILURE FAILED
 */
int runMonty(FILE *monty_file)
{
	ssize_t read;
	size_t  len = 0, exit_code = EXIT_SUCCESS;
	size_t getline(char **lineptr, size_t *n, FILE *stream);
	char *line = NULL;

	while ((read = getline(&line, &len, monty_file)) != -1)
	{
		fputs(line, stdout);
	}
	free(line);
	return (exit_code);
}
