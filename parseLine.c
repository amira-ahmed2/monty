#include "main.h"

/**
 * parseLine - Separates each line
 * @buff: line in file
 * @linNumber: line number
 * @format: format.
 * Return: 0 is stack, 1 is queue.
 */

int parseLine(char *buff, int linNumber, int format)
{
	char *opcode, *v;
	const char *del = "\n ";

	if (buff == NULL)
		errors(4);

	opcode = strtok(buff, del);
	if (opcode == NULL)
		return (format);
	v = strtok(NULL, del);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	giveFunc(opcode, v, linNumber, format);
	return (format);
}