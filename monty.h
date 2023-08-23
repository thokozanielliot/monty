#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_no);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void freeStack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void freeTok(void);
unsigned int tokLen(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void monty_push(stack_t **stack, unsigned int line_no);
void monty_pall(stack_t **stack, unsigned int line_no);
void monty_pint(stack_t **stack, unsigned int line_no);
void monty_pop(stack_t **stack, unsigned int line_no);
void monty_swap(stack_t **stack, unsigned int line_no);
void monty_add(stack_t **stack, unsigned int line_no);
void monty_nop(stack_t **stack, unsigned int line_no);
void monty_sub(stack_t **stack, unsigned int line_no);
void monty_div(stack_t **stack, unsigned int line_no);
void monty_mul(stack_t **stack, unsigned int line_no);
void monty_mod(stack_t **stack, unsigned int line_no);
void monty_pchar(stack_t **stack, unsigned int line_no);
void monty_pstr(stack_t **stack, unsigned int line_no);
void monty_rotl(stack_t **stack, unsigned int line_no);
void monty_rotr(stack_t **stack, unsigned int line_no);
void monty_stack(stack_t **stack, unsigned int line_no);
void monty_queue(stack_t **stack, unsigned int line_no);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);
size_t getline(char **lineptr, size_t *n, FILE *stream);

/* ERROR MESSAGES & ERROR CODES */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknownError(char *opcode, unsigned int line_no);
int no_int_error(unsigned int line_no);
int pop_error(unsigned int line_no);
int pint_error(unsigned int line_no);
int short_stack_error(unsigned int line_no, char *op);
int div_error(unsigned int line_no);
int pchar_error(unsigned int line_no, char *message);

#endif /* __MONTY_H__ */
