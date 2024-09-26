#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - list representation stack (or queue)
 * @n: integer
 * @prev: previous element of the stack (or queue)
 * @next: next element of the stack (or queue)
 *
 * Description: list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: opcode
 * @f: opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void open_files(char *file_name);
int parses_line(char *buffer, int line_number, int format);
void read_files(FILE *);
int len_chars(FILE *);
void find_function(char *, char *, int, int);
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void multiplies_nodes(stack_t **, unsigned int);
void modulus_nodes(stack_t **, unsigned int);
void call_function(op_func, char *, char *, int, int);
void print_charr(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void errors(int error_code, ...);
void more_errors(int error_code, ...);
void string_errors(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
