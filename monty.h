#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

/* ----- Data Structures ----- */

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

/* ----- Self-Functions ----- */

/* errors.c */
void throwCustomError(char *error, ...);

/* file_utils.c */
unsigned int accessFile(char *fileName);

/* opcodes */
void pushOpCode(stack_t **stack, unsigned int line_number);
void pallOpCode(stack_t **stack, unsigned int line_number);
void pintOpCode(stack_t **stack, unsigned int line_number);
void popOpCode(stack_t **stack, unsigned int line_number);
void swapOpCode(stack_t **stack, unsigned int line_number);
void addOpCode(stack_t **stack, unsigned int line_number);
void nopOpCode(stack_t **stack, unsigned int line_number);

#endif