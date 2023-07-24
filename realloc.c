#include "shell.h"

/**
 * set_memory - Fills memory with a constant byte.
 * @dest: Pointer to the memory area.
 * @val: The byte value to fill *dest with.
 * @size: The number of bytes to be filled.
 * Return: A pointer to the memory area dest.
 */
char *set_memory(char *dest, char val, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		dest[i] = val;
	return (dest);
}

/**
 * free_string_array - Frees an array of strings.
 * @array: Array of strings to be freed.
 */
void free_string_array(char **array)
{
	char **temp = array;

	if (!array)
		return;

	while (*array)
		free(*array++);
	free(temp);
}

/**
 * reallocate_memory - Reallocates a block of memory.
 * @ptr: Pointer to the previous allocated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the new block of memory.
 */
void *reallocate_memory(void *ptr, unsigned int old_size,
		unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];

	free(ptr);
	return (new_ptr);
}
