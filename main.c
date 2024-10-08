#include "main.h"

stack_t *head = NULL;

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Argument count.
 * @argv: List of arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_files(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a new node.
 * @n: The integer value to store in the node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 *
 * Return: void.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - Adds a new node to the end of the queue.
 * @new_node: Pointer to the new node to add.
 * @ln: Line number of the opcode.
 *
 * Return: void.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

