#include "monty.h"

/**
 * pintFun - prints the value at the top of the stack
 * @topNode: pointer top node in the stack.
 * @lnNum: int line number.
 */
void pintFun(stack_t **topNode, unsigned int lnNum)
{
	if (topNode == NULL || *topNode == NULL)
		moreError(6, lnNum);
	printf("%d\n", (*topNode)->n);
}