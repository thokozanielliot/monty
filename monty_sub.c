#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value)
{
	if (top < STACK_SIZE - 1)
	{
		top++;
		stack[top] = value;
	}
	else
	{
		fprintf(stderr, "Stack overflow\n");
		exit(EXIT_FAILURE);
	}
}

int pop()
{
	if (top >= 0)
	{
		return stack[top--];
	}
	else
	{
		fprintf(stderr, "Stack underflow\n");
		exit(EXIT_FAILURE);
	}
}

void sub()
{
	if (top < 1)
	{
		fprintf(stderr, "can't sub, stack too short\n");
		exit(EXIT_FAILURE);
	}
	int topValue = pop();
	int secondTopValue = pop();
	int result = secondTopValue - topValue;
	push(result);
}
