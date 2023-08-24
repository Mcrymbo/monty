#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 1024


/* include guard this header file using define and ifndef
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
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int type;
	unsigned int count;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global;


extern global glob;

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


/** aux_str.c**/
int _strcmp(char *s1, char *s2);
int char_search(char *str, char c);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, char *del);

/*implement_opcode.c */
void (*opcode_handle(char *op))(stack_t **stack, unsigned int line_number);

/*aux_mem.c*/
void _memcpy(void *dest, const void *src, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/** pint.c **/
void _pint(stack_t **stack, unsigned int line_number);

/* add_node.c */
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node_big(stack_t **head, const int n);
void free_list(stack_t *head);
void free_glob(void);

/** _getline.c **/
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
int fileno(FILE *stream);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/** opcodes **/
void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_num);
void _pop(stack_t **head, unsigned int line_num);

#endif
