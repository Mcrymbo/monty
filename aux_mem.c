#include "monty.h"

/**
 * _memcpy - copies information between void pointers
 * @dest: destination pointer
 * @src: soirce pointer
 * @size: size of dest pointer
 */
void _memcpy(void *dest, const void *src, unsigned int size)
{
	char *dst = (char *)dest;
	char *src_ptr = (char *)src;
	unsigned int i;

	for (i = 0; i < size; i++)
		dst[i] = src_ptr[i];
}
/**
 * _realloc - reallocates memory
 * @ptr: memory previousely allocated
 * @old_size: size of the preveousely allocated memory
 * @new_size: size of new memory
 * Return: no return
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);
	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}
