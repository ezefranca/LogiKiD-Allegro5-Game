/*#include "File.h"

// Forked from: http://stackoverflow.com/questions/252782/strdup-what-does-it-do-in-c
char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL)
        strcpy (d,s);                    // Copy string if okay
    return d;                            // Return new memory
}

char** readFile(const char *filename, size_t *lineCount)
{
	FILE *fp;
	char buff[4096];
	size_t lines = 0, capacity=1024;
	char **line;

	if(NULL==(fp=fopen(filename, "r")))
	{
	
		fprintf(stderr, "Impossivel abrir o arquivo\n.");
		return NULL;
	}

	if(NULL==(line=(char**)malloc(sizeof(char*)*capacity)))
	{
		fprintf(stderr, "Impossivel de alocar a memoria\n");
		fclose(fp);
		return NULL;
	}

	while(NULL!=fgets(buff, sizeof(buff), fp))
	{
		line[lines++] = strdup(buff);
		if(lines == capacity)
		{
			capacity += 32;
			if(NULL==(line=(char**)realloc(line, sizeof(char*)*capacity)))
			{
				fprintf(stderr, "Impossivel de alocar a memoria\n");
				fclose(fp);
				return NULL;
			}
		}
	}
	*lineCount = lines;
	fclose(fp);

	return (char**)realloc(line, sizeof(char*)*lines);
}

void freeMem(char** p, size_t size)
{
	size_t i;

	if(p==NULL)
	  return;

	for(i=0;i<size;++i)
		free(p[i]);
	free(p);
}

int split(char*** ret, char* instr, char* delim)
{
	char* str = strdup(instr);
 
	char** arr = (char**)malloc(sizeof(char*) * (strlen(instr)+1));
	int count = 0;
	char* result = NULL;
	result = strtok(str, delim);
	while (result != NULL)
	{
		arr[count] = strdup(result);
		count++;
		result = strtok(NULL, delim);
	}
 
	arr = (char**)realloc(arr, sizeof(char*) * (count+1));
 
	*ret = arr;
 
	free(str);
 
	return count;
}*/