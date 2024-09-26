#include "main.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "sub");

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "div");

	if ((*stack)->n == 0)
		more_errors(9, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

