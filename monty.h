#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

/* include guard this header file using define and ifndef */

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
 * struct global_data - holds golbal variables
 * @count: holds line number
 * @buffer: holds file data
 * @type: LIFO or FIFO information
 * @head: pointer to doubly linked list
 * @args: second argument
 */
typedef struct global_data
{
	int count;
	char *buffer;
	int type;
	stack_t *head;
	char *args;
} global_data;

/** handling_opcodes.c */
void (*opcode_handle(char *op))(stack_t **stack, unsigned int line_numer);
/** aux_mem.c **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/** _getline.c **/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);

#endif
