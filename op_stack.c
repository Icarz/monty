#include "main.h"

/**
 * multiplies_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void multiplies_nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modulus_nodes - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Return: void.
 */
void modulus_nodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "mod");

	if ((*stack)->n == 0)
		more_errors(9, line_number);

	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

