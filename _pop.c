#include "monty.h"

/**
 * _pop - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */


void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}
