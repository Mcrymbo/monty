#include "monty.h"
/**#define _POSIX_C_SOURCE 200809L
#include <stdio.h>**/

global_data glob;

/**
 * file_read - reads the file
 * @ac: argument count
 * @av: argument vector
 * Return: fd
 */
FILE *file_read(int ac, char **av)
{
	FILE *fd;
	char *file_name = av[1];

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
/**
 * set_data - initializes the glob var
 * Return: no return
 */
void set_data(void)
{
	glob.count = 1;
	glob.buffer = NULL;
	glob.type = 1;
	glob.head = NULL;
	glob.args = NULL;
}
/**
 * main - monty enterpreter
 * @ac: argument count
 * @av: argument vector
 * Return: EXIT_success on success or EXIT_FAILURE on error
 */
int main(int ac, char **av)
{
	FILE *fd;
	size_t size = 256;
	ssize_t nline = 0;
	char *line[2] = {NULL, NULL};
	void (*f)(stack_t **stack, unsigned int line_number);

	fd = file_read(ac, av);
	set_data();
	nline = getline(&glob.buffer, &size, fd);
	while (nline != -1)
	{
		line[0] = strtok(glob.buffer, " \t\n");
		if (line[0])
		{
			f = opcode_handle(line[0]);
			if (f == NULL)
			{
				fprintf(stderr, "L%d: unknown",glob.count);
				fprintf(stderr, " instruction %s\n", line[0]);
				exit(EXIT_FAILURE);
			}
			glob.args = strtok(NULL, " \t\n");
			f(&glob.head, glob.count);
		}
		/**nline = getline(getline(&glob.buffer, &size, fd));**/
		glob.count++;
	}
	return (0);
}
