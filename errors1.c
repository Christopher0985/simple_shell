#include "shell.h"
#include <stdio.h>

/**
 * convert_string_to_int - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Return: The converted number, or -1 on error.
 */
int convert_string_to_int(char *str)
{
	int i = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error_message - Prints an error message.
 * @info: Structure containing parameter and return information.
 * @error_type: String containing the specified error type.
 */
void print_error_message(info_t *info, char *error_type)
{
	write_string_to_stderr(info->cmd_filename);
	write_string_to_stderr(": ");
	print_decimal(info->cmd_line_counter, STDERR_FILENO);
	write_string_to_stderr(": ");
	write_string_to_stderr(info->cmd_argument_vector[0]);
	write_string_to_stderr(": ");
	write_string_to_stderr(error_type);
}

/**
 * print_decimal - Prints a decimal (integer) number (base 10).
 * @input: The input number.
 * @fd: The file descriptor to write to.
 *
 * Return: Number of characters printed.
 */
int print_decimal(int input, int fd)
{
	int (*custom_putchar)(char) = _write_char_to_stderr;
	int i, count = 0;
	unsigned int absolute_value, current;

	if (fd == STDERR_FILENO)
		custom_putchar = _write_char_to_stderr;
	if (input < 0)
	{
		absolute_value = -input;
		custom_putchar('-');
		count++;
	}
	else
		absolute_value = input;
	current = absolute_value;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absolute_value / i)
		{
			custom_putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	custom_putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number_to_string - Converts a number to a string with a given base.
 * @num: The number to convert.
 * @base: The base for conversion.
 * @flags: Argument flags.
 *
 * Return: The converted string.
 */
char *convert_number_to_string(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :
			"0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}

/**
 * remove_comments_from_string - Replaces first instance of '#' with '\0'.
 * @str: Address of the string to modify.
 */
void remove_comments_from_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '#' && (!i || str[i - 1] == ' '))
		{
			str[i] = '\0';
			break;
		}
}
