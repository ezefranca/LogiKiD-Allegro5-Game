/*
 * Este código faz o tratamento dos puzzles logicos
 * Inicio: 12/08/2013 - 01:33:xx AM
 * Autor: Alexandre Savelli Bencz
 */

#include "lEngine.h"

struct AstLogic ast1, ast2, ast3;

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
	ast3.result = ~(ast1.input1|ast1.input2);

	ast2.gate = NOR;
	ast2.input1 = true;
	ast2.input2 = false;
	ast2.result = ~(ast2.input1|ast2.input2);
	ast1.nextGate = &ast2; // make the link

	ast3.gate = NOR;
	ast3.input1 = ast1.result;
	ast3.input2 = ast2.result;
	ast3.result = ~(ast3.input1|ast3.input2);

	if(ast3.result == true)
		printf("true");
	else
		printf("false");
}

void executeTest()
{
	createInputsTest();
}

bool inputLogic(FILE *inp)
{
	return 0;
}

void ConfirmeLogic()
{
}
