#include "main.h"

/**
 * readFile - read any file
 * @fd: file descriptor
 */

void readFile(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parseLine(buffer, line_number, format);
	}
	free(buffer);
}