#include "main.h"

/**
 * print_charr - Prints the ASCII value of the top element.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void print_charr(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_errors(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_errors(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_string - Prints a string from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

