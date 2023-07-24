#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

/**
 * _eputs - Error handling function to print a string to stderr.
 * @str: The string to be printed.
 *
 * Description: This function is used for error handling in the shell
 * program. It prints the specified string to the std error stream (stderr)
 */
void _eputs(const char *str)
{
	fprintf(stderr, "%s", str);
}

/**
 * shell_main - Entry point of the shell program.
 * @argc: The number of arguments passed to the shell program.
 * @argv: An array of strings containing the arguments passed to the shell.
 *
 * Return: 0 on success, 1 on error.
 */
int shell_main(int argc, char **argv)
{
	void _eputs(const char *str);
	int populate_custom_environment_list(info_t *info);
	int read_history_from_file(info_t *info);
	int my_shell(info_t *info, char **argv);

	info_t shell_info = {0};
	int fd = 2;

	asm volatile("mov %1, %0\n\t"
				 "add $3, %0"
				 : "=r"(fd)
				 : "r"(fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
			{
				exit(150);
			}

			if (errno == ENOENT)
			{
				_eputs("Error: ");
				_eputs("Cannot open file '");
				_eputs(argv[1]);
				_eputs("'\n");
				exit(151);
			}
			return (EXIT_FAILURE);
		}
		shell_info.cmd_read_file_descriptor = fd;
	}

	populate_custom_environment_list(&shell_info);
	read_history_from_file(&shell_info);
	my_shell(&shell_info, argv);
	return (EXIT_SUCCESS);
}
