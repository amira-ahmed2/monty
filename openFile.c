#include "main.h"

/**
 * openFile -open file
 * @fname: the file namepath
 * Return: void
 */

void openFile(char *fname)
{
	FILE *fd = fopen(fname, "r");

	if (fname == NULL || fd == NULL)
		errors(2, fname);

	readFile(fd);
	fclose(fd);
}