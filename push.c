#include "monty.h"

/**
 * digit - function that a string only contains digits.
 * @arg: argument
 *
 * Return: 0 or 1 if a non-integer character is found
 */

int digit(char *str)
{
	unsigned int i;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (isdigit(str[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * push - function that creates a new linked list node
 *@stack: pointer to the beginning of the satck
 *@line_number: script line number
 * Return: nothing
 */

void stackpush(stack_t **stack, unsigned int line_number)
{
	stack_t	*temp = NULL; 

	char *arg = NULL;

	arg = strtok(NULL, "\t\r\n");

	if (arg == NULL || digit(arg) == 1)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(arg);
	temp->prev = NULL;
	temp->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = temp;

	*stack = temp;
}
