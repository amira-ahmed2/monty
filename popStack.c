#include "monty.h"

/**
 * popStack - removes the top element of the stack.
 * @topNode: pointer top node in the stack.
 * @lnNum: int line number.
 */
void popStack(stack_t **topNode, unsigned int lnNum)
{
	stack_t *temp;

	if (topNode == NULL || *topNode == NULL)
		moreError(7, lnNum);

	temp = *topNode;
	*topNode = temp->next;
	if (*topNode != NULL)
		(*topNode)->prev = NULL;
	free(temp);
}