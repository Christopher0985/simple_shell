#include "shell.h"

/**
 * free_and_null - Frees the memory pointed to by a pointer and sets it to NULL
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if the memory is freed, otherwise 0.
 */
int free_and_null(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}
