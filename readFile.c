#include "main.h"
#include <stdio.h>

/**
 * readFile - read any file
 * @fd: file descriptor
 */

void readFile(FILE *fd)
{
	int linNum, f = 0;
	char *buff = NULL;
	size_t length = 0;

	for (linNum = 1; getline(&buff, &length, fd) != -1; linNum++)
	{
		f = parseLine(buff, linNum, f);
	}
	free(buff);
}