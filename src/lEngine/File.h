#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** readFile(const char *filename, size_t *lineCount);
void freeMem(char** p, size_t size);
