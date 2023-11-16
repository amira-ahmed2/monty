#include "monty.h"

/**
 * errors - error messages.
 * @errorCode: The error codes
 */
void errors(int errorCode, ...)
{
	va_list argc;
	char *opr;
	int numLine;

	va_start(argc, errorCode);
	switch (errorCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argc, char *));
			break;
		case 3:
			numLine = va_arg(argc, int);
			opr = va_arg(argc, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", numLine, opr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argc, int));
			break;
		default:
			break;
	}
	freeAllNode();
	exit(EXIT_FAILURE);
}

/**
 * moreError - error messages.
 * @errorCode: The error codes
 */
void moreError(int errorCode, ...)
{
	va_list argc;
	char *opr;
	int numLine;

	va_start(argc, errorCode);
	switch (errorCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argc, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argc, int));
			break;
		case 8:
			numLine = va_arg(argc, unsigned int);
			opr = va_arg(argc, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", numLine, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argc, unsigned int));
			break;
		default:
			break;
	}
	freeAllNode();
	exit(EXIT_FAILURE);
}

/**
 * moreError - error messages.
 * @errorCode: The error codes
 */
void errString(int errorCode, ...)
{
	va_list argc;
	int numLine;

	va_start(argc, errorCode);
	numLine = va_arg(argc, int);
	switch (errorCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", numLine);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", numLine);
			break;
		default:
			break;
	}
	freeAllNode();
	exit(EXIT_FAILURE);
}