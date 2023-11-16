#include "monty.h"
stack_t *head = NULL;
/**
 * freeAllNode - Frees all node the stack.
 */
void freeAllNode(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}