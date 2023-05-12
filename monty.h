#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

/* ----- Data Structures ----- */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 **/
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
 * struct file_s - opcode and its function
 * @file: file name
 * @f: file descriptor
 * @n_line: number of line
 * @args: arguments
 * Description: file info
 **/
typedef struct file_s
{
	char *file;
	FILE *f;
	unsigned int n_line;
	char **arr;
	char *line;
	stack_t *stack;
	
} file_t;

extern file_t file_info;


/* ----- Self-Functions ----- */

/* main.c */
void checkInstructions(char *fileName, stack_t **s);

/* errors.c */
void throwCustomError(char *error, ...);
void free_all();
void free_stack(stack_t *head);

/* file_utils.c */
unsigned int accessFile(char *fileName);

/* opcodes */
void pushOpCode(stack_t **stack, int val);
void pallOpCode(stack_t **stack, unsigned int line_number);
void pintOpCode(stack_t **stack, unsigned int line_number);
void popOpCode(stack_t **stack, unsigned int line_number);
void swapOpCode(stack_t **stack, unsigned int line_number);
void addOpCode(stack_t **stack, unsigned int line_number);
void nopOpCode(stack_t **stack, unsigned int line_number);

/* stack_utils.c */
int deleteStack(stack_t **head, unsigned int index);
void clearStack();

/* instruction_utils.c */
int ex_instruction(char *oC, unsigned int l, int v, stack_t **s);
int chek_push_usage(char **arr);
int is_num(char *arr);

/* string_utils.c */
void free_array(char **arr);
int only_spaces(char *line);
char **tokenize(char *line);

#endif
