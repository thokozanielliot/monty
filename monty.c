#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the entry point for Monty Interpreter
 * @ac: arguments count
 * @av: arguments vector
 * Return: on success (EXIT_SUCCESS) otherwise (EXIT_FAILURE)
 */
int main(int ac, char **av)
{	
	FILE *monty_file = NULL;
	int exit_code = EXIT_SUCCESS;

	if (ac != 2)
		return (usage_error());
	monty_file = fopen(av[1], "r");
	if (monty_file == NULL)
		return (f_open_error(av[1]));
	exit_code = run_monty(monty_file);
	fclose(monty_file);
	return (exit_code);
}
