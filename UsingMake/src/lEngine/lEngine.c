/*
 * Este código faz o tratamento dos puzzles logicos
 * Inicio: 12/08/2013 - 01:33:xx AM
 * Autor: Alexandre Savelli Bencz
 */

#include "lEngine.h"
#include "File.h"

struct AstLogic ast1, ast2, ast3, ast4;

//
//     1-|ast1|
//     1-|____|+-------+
//                     |
//                     +|ast3|
//                     +|____|+----+ OUTPUT
//                     |
//     1-|ast2|+-------+
//     0-|____|
//

void createInputsTest()
{
	ast1.gate = NOR;
	ast1.input1 = true;
	ast1.input2 = true;
	ast1.nextGate = &ast3;

	ast2.gate = NOR;
	ast2.input1 = true;
	ast2.input2 = false;
	ast2.nextGate = &ast3;

	ast3.gate = NOR;
	ast1.nextGate->input1 = !(ast1.input1|ast1.input2);
	ast2.nextGate->input2 = !(ast2.input1|ast2.input2);
	ast3.nextGate = &ast4;
	ast3.result = !(ast3.input1|ast3.input2);

	ast4.gate = AND;
	ast4.input1 = ast3.result;
	ast4.input2 = !(ast2.input1|ast2.input2);
	ast4.result = (ast4.input1 && ast4.input2);

	if(ast4.result == true)
		printf("true");
	else
		printf("false");
}

void executeTest()
{
	createInputsTest();
}

bool inputLogic(const char *FileName)
{
	int i = 0, j = 0, n = 0;
	size_t lines;
	char **line, **outbuf;

	if(NULL!=(line=readFile(FileName, &lines)))
	{
		for(i=0;i<lines;i++)
		{
			n = split(&outbuf, line[i], " ");
			//...
			for(j=0;j<n;j++)
			{
				printf("%s\n", outbuf[j]);
				free(outbuf[j]);
			}
		}
	}
	freeMem(line, lines);
	free(outbuf);
	
	return true;
}

void ConfirmeLogic(){
}
