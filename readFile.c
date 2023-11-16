#include "monty.h"
#include <stdio.h>

/**
 * readFile - read any file
 * @fd: file descriptor
 */

void readFile(FILE *fd)
{
int linNum = 1, f = 0;
char *buff = NULL;
size_t length = 0;

while (getline(&buff, &length, fd) != -1)
{
f = parseLine(buff, linNum, f);
linNum++;
}
free(buff);
}
