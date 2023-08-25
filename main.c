#include "monty.h"

global glob; /* global variable to hold the state of the program*/

/**
 * free_glob - frees global variable
 */
void free_glob(void)
{
	free_list(glob.head);
	free(glob.buffer);
	fclose(glob.fd);
}

/**
 * file_read - reads the file
 * @ac: argument count
 * @av: argument vector
 * Return: fd
 */
FILE *file_read(int ac, char **av)
{
	FILE *fd;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
/**
 * set_data - initializes the glob var
 * @fd: file descriptor
 * Return: no return
 */
void set_data(FILE *fd)
{
	glob.type = 1;
	glob.count = 1;
	glob.arg = NULL;
	glob.head = NULL;
	glob.fd = fd;
	glob.buffer = NULL;
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
	set_data(fd);
	nline = getline(&glob.buffer, &size, fd);
	while (nline != -1)
	{
		line[0] = _strtok(glob.buffer, " \t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = opcode_handle(line[0]);
			if (!f)
			{
				fprintf(stderr, "L%d: unknown", glob.count);
				fprintf(stderr, " instruction %s\n", line[0]);
				free_glob();
				exit(EXIT_FAILURE);
			}
			glob.arg = _strtok(NULL, " \t\n");
			f(&glob.head, glob.count);
		}
		nline = getline(&glob.buffer, &size, fd);
		glob.count++;
	}
	free_glob();
	return (0);
}
