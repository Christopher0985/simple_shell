#include "shell.h"

/**
 * get_string_length - Calculates the length of a string.
 * @str: Pointer to the string whose length needs to be determined.
 *
 * Return: The integer length of the string.
 */
int get_string_length(char *str)
{
	int length = 0;

	if (!str)
		return (0);

	while (*str++)
		length++;
	return (length);
}

/**
 * compare_strings - Performs a lexicographic comparison of two strings.
 * @str1: Pointer to the first string to compare.
 * @str2: Pointer to the second string to compare.
 *
 * Return: Negative value if str1 < str2, positive value if str1 > str2,
 * 0 if str1 == str2.
 */
int compare_strings(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with_substring - Checks if a string starts with a specific substring.
 * @str: Pointer to the string to search.
 * @substring: Pointer to the substring to find at the beginning of the string.
 *
 * Return: Address of the next character after the substring in 'str',
 * or NULL if not found.
 */
char *starts_with_substring(const char *str, const char *substring)
{
	while (*substring)
	{
		if (*substring++ != *str++)
			return (NULL);
	}
	return ((char *)str);
}

/**
 * concatenate_strings - Concatenates two strings.
 * @destination: Pointer to the destination buffer where the result is stored.
 * @source: Pointer to the source buffer containing the string to append.
 *
 * Return: Pointer to the destination buffer.
 */
char *concatenate_strings(char *destination, char *source)
{
	char *ret = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (ret);
}
