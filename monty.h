#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct struct_m - opcode and its function
 * @token2: second argument
 * @buffer: line text
 * @fp: file pointer
 *
 * Description: free variables
 */
typedef struct struct_m
{
	char *token2;
	char *buffer;
	FILE *fp;
} struct_f;

extern struct_f f_struct;
struct_f f_struct;

void valid_opcodes(char *buffer, unsigned int lines, stack_t **stack);
void free_stack(stack_t **stack);
int is_number(char *str);

void _push(stack_t **stack, unsigned int lines);
void _pall(stack_t **stack, unsigned int lines);
void _pint(stack_t **stack, unsigned int lines);
void _swap(stack_t **stack, unsigned int lines);
void _nop(stack_t **stack, unsigned int lines);
void _pop(stack_t **stack, unsigned int lines);
void _add(stack_t **stack, unsigned int lines);
void _sub(stack_t **stack, unsigned int lines);
void _div(stack_t **stack, unsigned int lines);

#endif
