#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

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

/* main.c */
void checkInstructions(char *fileName, stack_t **s);

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

/* stack_utils.c */
int deleteStack(stack_t **head, unsigned int index);
stack_t *getStack(unsigned int position);
void clearStack();

/* instruction_utils.c */
unsigned int ex_instruction(char *opCode, unsigned int line, int val, stack_t **stack);

/* string_utils.c */
char **split_str(char *str, const char *delim);
int str_count_words(char *s, const char *delim);
void free_array(char **arr);

#endif
