#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>

#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define COMMAND_NORMAL		0
#define COMMAND_OR		1
#define COMMAND_AND		2
#define COMMAND_CHAIN		3

#define CONVERT_START_LOWER	1
#define CONVERT_END_LOWER	2
#define CONVERT_START_UPPER	3
#define CONVERT_END_UPPER	4

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HISTORY_FILE	".my_shell_history"
#define MAX_HISTORY	4096

extern char **custom_environ;

typedef struct list_node
{
	int node_number;
	char *node_string;
	struct list_node *next;
} list_t;

typedef struct pass_info
{
	char *cmd_arguments;
	char **cmd_argument_vector;
	char *cmd_path;
	int cmd_argument_count;
	unsigned int cmd_line_counter;
	int cmd_error_number;
	int cmd_linecount_flag;
	char *cmd_filename;
	list_t *cmd_environment;
	list_t *cmd_history;
	list_t *cmd_alias;
	char **cmd_custom_environ;
	int cmd_environment_changed;
	int cmd_execution_status;
	char **cmd_buffer;
	int cmd_buffer_type;
	int cmd_read_file_descriptor;
	int cmd_history_count;
} info_t;

int my_shell(info_t *, char **);
int find_builtin_command(info_t *);
void find_command(info_t *);
void fork_command(info_t *);

int is_command(info_t *, char *);
char *duplicate_characters(char *, int, int);
char *find_path(info_t *, char *, char *);

int loop_my_shell(char **);

void print_error_str(char *);
int print_error_char(int);
int put_char_to_file(char c, int fd);
int put_string_to_file(char *str, int fd);

int string_length(char *);
int compare_strings(char *, char *);
char *starts_with_substring(const char *, const char *);
char *concatenate_strings(char *, char *);

char *copy_string(char *, char *);
char *duplicate_string(const char *);
void print_string(char *);
int print_character(char);

char *copy_string_with_limit(char *, char *, int);
char *concatenate_string_with_limit(char *, char *, int);
char *find_character(char *, char);

char **split_string(char *, char *);
char **split_string_v2(char *, char);

char *set_memory(char *, char, unsigned int);
void free_tokens(char **);
void *resize_memory(void *, unsigned int, unsigned int);

int free_buffer(void **);

int is_interactive_shell(info_t *);
int is_character_delimiter(char, char *);
int is_alphanumeric_character(int);
int convert_string_to_integer(char *);

int error_string_to_integer(char *);
void print_custom_error(info_t *, char *);
int print_integer_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int my_exit(info_t *);
int my_change_directory(info_t *);
int my_help(info_t *);

int my_history(info_t *);
int my_alias(info_t *);

ssize_t get_user_input(info_t *);
int get_user_input_line(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info_struct(info_t *);
void set_info_struct(info_t *, char **);
void free_info_struct(info_t *, int);

char *get_custom_environment_variable(info_t *, const char *);
int my_custom_environment(info_t *);
int my_set_custom_environment(info_t *);
int my_unset_custom_environment(info_t *);
int populate_custom_environment_list(info_t *);

char **get_custom_environ(info_t *);
int my_unset_custom_environment_variable(info_t *, char *);
int my_set_custom_environment_variable(info_t *, char *, char *);

char *get_history_file(info_t *info);
int write_history_to_file(info_t *info);
int read_history_from_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_of_strings(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_linked_list(list_t **);

size_t linked_list_length(const list_t *);
char **linked_list_to_strings(list_t *);
size_t print_linked_list(const list_t *);
list_t *find_node_starts_with(list_t *, char *, char);
ssize_t find_node_index(list_t *, list_t *);

int is_chain_delimiter(info_t *, char *, size_t *);
void check_chain_delimiter(info_t *, char *, size_t *, size_t, size_t);
int replace_alias_in_cmd(info_t *);
int replace_variables_in_cmd(info_t *);
int replace_string_in_cmd(char **, char *);

void _eputs(const char *str);

#endif
