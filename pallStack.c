#include "main.h"

/**
 * pallStack - add a node to the stack.
 * @node:top node of the stack.
 * @lineNum: line number
 */
void pallStack(stack_t **node, unsigned int lineNum)
{
	stack_t *temp;

	(void) lineNum;
	if (node == NULL)
		exit(EXIT_FAILURE);
	temp = *node;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
