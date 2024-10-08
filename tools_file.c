#include "main.h"

/**
 * open_files - Opens a file.
 * @file_name: The path of the file to open.
 *
 * Return: void.
 */
void open_files(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		errors(2, file_name);

	read_files(fd);
	fclose(fd);
}

/**
 * read_files - Reads a file line by line.
 * @fd: Pointer to the file descriptor.
 *
 * Return: void.
 */
void read_files(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parses_line(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * parses_line - Parses a line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @line_number: The line number in the file.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 *
 * Return: 0 if the opcode is for stack, 1 if for queue.
 */
int parses_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		errors(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, line_number, format);
	return (format);
}

/**
 * find_function - Finds the appropriate function for the opcode.
 * @opcode: The opcode string.
 * @value: Argument for the opcode.
 * @ln: Line number of the instruction.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 *
 * Return: void.
 */
void find_function(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", multiplies_nodes},
		{"mod", modulus_nodes},
		{"pchar", print_charr},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, ln, opcode);
}

/**
 * call_function - Calls the required function for the opcode.
 * @func: Pointer to the function to call.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @format: Format specifier. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 *
 * Return: void.
 */
void call_function(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

