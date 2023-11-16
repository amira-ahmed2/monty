#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#define _GNU_SOURCE

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

extern stack_t *head;
typedef void (*operators_func)(stack_t **, unsigned int lin_num);
void openFile(char *fname);
void readFile(FILE *fd);
void errors(int errorCode, ...);
void moreError(int errorCode, ...);
void errString(int errorCode, ...);
int parseLine(char *buff, int linNumber, int format);
void freeAllNode(void);
void getFunc(operators_func func, char *op, char *val, int lineNum, int format);
void giveFunc(char *opcode, char *value, int lineNum, int format);
stack_t *createN(int num);




#endif