#include "monty.h"
#include <string.h>

void freeTok(void);
unsigned int tokLen(void);
int emptyLine(char *line, char *delims);
void (*operationFunction(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *monty_file);

/**
 * freeTok - Frees the global op_toks array of strings.
 */
void freeTok(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tokLen - Gets the length of current op_toks.
 * Return: Length of current op_toks
 */
unsigned int tokLen(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * emptyLine - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: delimiter characters.
 * Return: 1 if line contains delimeter otherwise - 0.
 */
int emptyLine(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * operationFunction - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 * Return: relevant function.
 */
void (*operationFunction(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty script.
 * @monty_file: File descriptor for a Monty script.
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE
 */
int run_monty(FILE *monty_file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_no = 0, prevTokLen = 0;
	void (*op_func)(stack_t**, unsigned int);
	size_t getline(char **lineptr, size_t *n, FILE *stream);
	ssize_t read;

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while ((read = getline(&line, &len, monty_file)) != -1)
	{
		line_no++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (emptyLine(line, DELIMS))
				continue;
			freeStack(&stack);
			fprintf(stderr, "Error: malloc failed\n");
			return (EXIT_FAILURE);
			
		}
		else if (op_toks[0][0] == '#')
		{
			freeTok();
			continue;
		}
		op_func = operationFunction(op_toks[0]);
		if (op_func == NULL)
		{
			freeStack(&stack);
			exit_status = unknownError(op_toks[0], line_no);
			freeTok();
			break;
		}
		prevTokLen = tokLen();
		op_func(&stack, line_no);
		if (tokLen() != prevTokLen)
		{
			if (op_toks && op_toks[prevTokLen])
				exit_status = atoi(op_toks[prevTokLen]);
			else
				exit_status = EXIT_FAILURE;
			freeTok();
			break;
		}
		freeTok();
	}
	freeStack(&stack);

	if (line && *line == 0)
	{
		free(line);
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	free(line);
	return (exit_status);
}
