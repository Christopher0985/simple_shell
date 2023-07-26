#include "shell.h"

/**
 * _write_char_to_stderr - Writes a character to the standard error.
 * @c: The character to print.
 *
 * Return: On success, the number of characters written is returned.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write_char_to_stderr(char c)
{
	static int index;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
	{
		write(STDERR_FILENO, buffer, index);
		index = 0;
	}

	if (c != BUF_FLUSH)
		buffer[index++] = c;

	return (1);
}

/**
 * _write_str_to_stderr - Writes a string to the standard error.
 * @str: The string to be written.
 *
 * Return: On success, the number of characters written is returned.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write_str_to_stderr(char *str)
{
	int index = 0;

	if (str == NULL)
		return (-1);

	while (str[index] != '\0')
		_write_char_to_stderr(str[index++]);

	return (index);
}
