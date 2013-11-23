#include "Player.h"
#include "comum.h"
#include "pontuacao.h"
#include <string.h>


int qualificaJogador (Player *player, int gameLevel){

	if (gameLevel == 0)
	{
		if (player->chances > 1)
			printf("excelente");
	}

	if (gameLevel == 1)
	{
		if (player->chances > 1)
			printf("excelente");
	}

	if (gameLevel == 2)
	{
		if (player->chances > 2)
			printf("excelente");
	}

	if (gameLevel == 3)
	{
		if (player->chances == 2)
			printf("excelente");
	}

	return 1;

}