#include "main.h"

/**
 * pushStack - add last node in stack
 * @node: the new node.
 * @ln: interger the line number opcode.
 */
void pushStack(stack_t **node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}
