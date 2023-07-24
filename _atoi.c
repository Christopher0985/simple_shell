#include "shell.h"

/**
 * is_interactive - Checks if the shell is running in interactive mode
 * @shell_info: Pointer to the info_t struct.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int is_interactive(info_t *shell_info)
{
	return (isatty(STDIN_FILENO)
			&& shell_info->cmd_read_file_descriptor <= 2);
}

/**
 * is_character_delimiter - Checks if a character is a delimiter.
 * @ch: The character to check.
 * @delimiter_str: The delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_character_delimiter(char ch, char *delimiter_str)
{
	while (*delimiter_str)
	{
		if (*delimiter_str++ == ch)
			return (1);
	}
	return (0);
}

/**
 * is_alphabetic - Checks if a character is alphabetic.
 * @ch: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int is_alphabetic(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * string_to_integer - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Return: The converted number if there are numbers in the string, 0 otherwise
 */
int string_to_integer(char *str)
{
	int index, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (index = 0; str[index] != '\0' && flag != 2; index++)
	{
		if (str[index] == '-')
			sign *= -1;

		if (str[index] >= '0' && str[index] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
