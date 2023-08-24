#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <strings.h>

#define DELIMS " \n\t\a\b"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: Check if stack or queue
 * @curr: Current line
 * @arg: 2nd parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: Text
 *
 * Description: Doubly linked list node for stack, queues
 */
typedef struct globals
{
	int lifo;
	unsigned int curr;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t globv;

void free_globv(void);
void start_globv(FILE *fd);
FILE *check_input(int ac, char *av[]);
int main(int ac, char *av[]);
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

int _strcmp(char *s1, char *s2);
int _searchChar(char *s, char c);
char *_strtow(char *s, char *delim);

stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

void _push(stack_t **doubly, unsigned int cline);
void _pall(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);

void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);

#endif
