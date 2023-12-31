#include "monty.h"

/**
 * giveFunc - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @lineNum: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void giveFunc(char *opcode, char *value, int lineNum, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", pushStack},
		{"pall", pallStack},
		{"add", pushStack},
		{"pint", pintFun},
		{"pop", popStack},
		{"nop", _nop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			getFunc(func_list[i].f, opcode, value, lineNum, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, lineNum, opcode);
}


/**
 * getFunc - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @lineNum: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void getFunc(operators_func func, char *op, char *val, int lineNum, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, lineNum);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, lineNum);
		}
		node = createN(atoi(val) * flag);
		if (format == 0)
			func(&node, lineNum);
	}
	else
		func(&head, lineNum);
}