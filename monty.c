#include "monty.h"


/**
 * main - entry point
 * @argc: arguments num argv
 * @argv: list arguments
 * Return: int
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeAllNode();
	return (0);
}



/**
 * createN - create node.
 * @num: number the node.
 * Return: the node.
 */
stack_t *createN(int num)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = num;
	return (node);
}