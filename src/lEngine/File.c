#include "File.h"

char** readFile(const char *filename, size_t *lineCount)
{
	FILE *fp;
	char buff[4096];
	size_t lines = 0, capacity=1024;
	char **line;

	if(NULL==(fp=fopen(filename, "r")))
	{
		perror("Impossivel abrir o arquivo."); // lembrar de fazer o tratamento para funcionar com a allegro
		return NULL;
	}

	if(NULL==(line=(char**)malloc(sizeof(char*)*capacity)))
	{
		perror("Impossivel de alocar a memoria"); // lembrar de fazer o tratamento para funcionar com a allegro
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
				perror("Impossivel alocar a memoria"); // lembrar de fazer o tratamento para funcionar com a allegro
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

/*
 * Teste...
 */
/*int main(int argc, char **argv)
{
	int i = 0;
	size_t lines;
	char **line;

	if(NULL!=(line=readFile("teste.txt", &lines)))
	{
		for(i=0;i<lines;i++)
			printf("%s", line[i]);
	}
	freeMem(line, lines);
	return 0;
}*/
