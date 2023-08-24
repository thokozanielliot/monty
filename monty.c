#include "monty.h"

void free_globv(void);
void start_globv(FILE *fd);
FILE *check_input(int ac, char *av[]);
int main(int ac, char *av[]);
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

global_t globv;

/**
 * free_globv - Free global variables
 *
 * Return: No return
 */
void free_globv(void)
{
	free_dlistint(globv.head);
	free(globv.buffer);
	fclose(globv.fd);
}

/**
 * start_globv - Initialize global variables
 * @fd: Filedescriptor
 *
 * Return: No return
 */
void start_globv(FILE *fd)
{
	globv.lifo = 1;
	globv.curr = 1;
	globv.arg = NULL;
	globv.head = NULL;
	globv.fd = fd;
	globv.buffer = NULL;
}

/**
 * check_input -  Check if file exists and can be opened
 * @ac: Arguement count
 * @av: Arguement vector
 *
 * Return: File
 */
FILE *check_input(int ac, char *av[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: CAn't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - Entry point
 * @ac: Arguement count
 * @av: Arguement vector
 *
 * Return: 0 on success otherwise failed
 */
int main(int ac, char *av[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;/* getline(char **lineptr, size_t *n, FILE *stream);*/
	ssize_t nlines;
	char *lines[2] = {NULL, NULL};

	fd = check_input(ac, av);
	start_globv(fd);
	nlines = getline(&globv.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtow(globv.buffer, DELIMS);
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", globv.curr);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_globv();
				exit(EXIT_FAILURE);
			}
			globv.arg = _strtow(NULL, DELIMS);
			f(&globv.head, globv.curr);
		}
		nlines = getline(&globv.buffer, &size, fd);
		globv.curr++;
	}
	free_globv();
	return (0);
}

/**
 * get_opcodes - Get opcode function to perform
 * @opc: opcode
 *
 * Return: Pointer to function to execute
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"np", _nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
