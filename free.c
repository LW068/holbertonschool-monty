#include "monty.h"

/**
 * free_sg - free stack and globals
 * @stack: stack head
 * Return: void
 */
void free_sg(stack_t **stack)
{
	stack_t *scrubber;

	if (GlobalVar)
	{
		free(GlobalVar[0]);
		free(GlobalVar);
	}
	if (*stack)
	{
		while (*stack)
		{
			scrubber = (*stack)->next;
			free(*stack);
			(*stack) = scrubber;
		}
	}
}
