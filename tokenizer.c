#include "shell.h"

/**
 * is_delimiter - Checks if a character is a delimiter.
 * @c: The character to check.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == ';' || c == '|' || c == '&');
}

/**
 * tokenize_string - Tokenizes a string into an array of tokens.
 * @input: The input string to tokenize.
 *
 * Return: An array of tokens (strings).
 */
char **tokenize_string(char *input)
{
	int buffer_size = TOKEN_BUFFER_SIZE;
	int token_count = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
		return (NULL);

	token = strtok(input, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[token_count] = token;
		token_count++;

		if (token_count >= buffer_size)
		{
			buffer_size += TOKEN_BUFFER_SIZE;
			tokens = realloc
				(tokens, buffer_size * sizeof(char *));
			if (!tokens)
				return (NULL);
		}

		token = strtok(NULL, TOKEN_DELIMITERS);
	}

	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * split_commands - Splits a string of commands based on '&' delimiter.
 * @input: The input string to split.
 *
 * Return: An array of strings representing commands.
 */
char **split_commands(char *input)
{
	int buffer_size = CMD_BUFFER_SIZE;
	int command_count = 0;
	char **commands = malloc(buffer_size * sizeof(char *));
	char *command;

	if (!commands)
		return (NULL);

	command = strtok(input, CMD_DELIMITER);
	while (command)
	{
		commands[command_count] = command;
		command_count++;

		if (command_count >= buffer_size)
		{
			buffer_size += CMD_BUFFER_SIZE;
			commands = realloc(commands,
					buffer_size * sizeof(char *));
			if (!commands)
				return (NULL);
		}

		command = strtok(NULL, CMD_DELIMITER);
	}

	commands[command_count] = NULL;
	return (commands);
}
