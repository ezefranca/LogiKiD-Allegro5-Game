/*
 * Rotina de pontuação e qualificação ao termino das fases
 * Autor: Ezequiel França dos Santos
 */
#include "Player.h"
#include "comum.h"
#include "pontuacao.h"
#include <string.h>

 Ranked *ranking;

 /*
Função que alloca as imagens da struct ranking
*/
void criaQualificacao(Ranked *ranking) {
	ranking->imageExcelente =  al_load_bitmap("./data/levels/menu/EXCELENTE.png");
	ranking->imageBom = al_load_bitmap("./data/levels/menu/MUITOBOM.png");
	ranking->imageRegular= al_load_bitmap("./data/levels/menu/REGULAR.png");
	ranking->imageGameover= al_load_bitmap("./data/levels/menu/GAMEOVER.png");
 //Futura implementação preve musica exclusiva para ranking
 	//ranking->somExcelente = al_load_sample("./data/sound/menu_open.wav");
 	//ranking->somBom = al_load_sample("./data/sound/menu_open.wav");
 	//ranking->somRegular = al_load_sample("./data/sound/menu_open.wav");
}


/*
Função para exibição da tela de premiação.
*/
void loopQualifica(ALLEGRO_EVENT *ev){
	bool sair = false;
	al_flip_display();
	system("cd ./data ; ./arduino-serial -b 9600 -p /dev/ttyACM1 -s off");
	while(!sair)
	{
		al_wait_for_event(game.fila_eventos, ev);
		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			sair = true;
		if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev->keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
				case ALLEGRO_KEY_ENTER:
				sair = true;
				break;
			}
		}
	}
}
/*
Função que recebe a struct player, recebe o level do jogo e o evento principal do allegro.
Recebe a struct player para manipulação e acesso do valor chances, que representa o numero
de movimentos. Recebe o level para classificar cada um diferentemente.
*/

int qualificaJogador (Player *player, int gameLevel,  ALLEGRO_EVENT *ev){

	if (gameLevel == 0)
	{
		ranking = malloc(sizeof(Ranked));
		criaQualificacao(ranking);
		if (player->chances != 0){
			al_draw_bitmap(ranking->imageExcelente, 0, 0, 0);
			loopQualifica(ev);
			printf("excelente entrou nesse caraio\n");
		}
	}

	if (gameLevel == 1)
	{

		if (player->chances == 3){
			al_draw_bitmap(ranking->imageExcelente, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 3 &&  player->chances < 10){
			al_draw_bitmap(ranking->imageBom, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 10){
			al_draw_bitmap(ranking->imageRegular, 0, 0, 0);
			loopQualifica(ev);
		}
	}

	if (gameLevel == 2)
	{
		if (player->chances == 1){
			al_draw_bitmap(ranking->imageExcelente, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 1 &&  player->chances < 4){
			al_draw_bitmap(ranking->imageBom, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 4){
			al_draw_bitmap(ranking->imageRegular, 0, 0, 0);
			loopQualifica(ev);
		}
	}

	if (gameLevel == 3)
	{
		if (player->chances >= 1 && player->chances <= 3){
			al_draw_bitmap(ranking->imageExcelente, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 3 &&  player->chances < 10){
			al_draw_bitmap(ranking->imageBom, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 10){
			al_draw_bitmap(ranking->imageRegular, 0, 0, 0);
			loopQualifica(ev);
		}
	}
	if(gameLevel == 4){
		if (player->chances == 2){
			al_draw_bitmap(ranking->imageExcelente, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 2 &&  player->chances < 4){
			al_draw_bitmap(ranking->imageBom, 0, 0, 0);
			loopQualifica(ev);
		}

		if (player->chances > 4){
			al_draw_bitmap(ranking->imageRegular, 0, 0, 0);
			loopQualifica(ev);
		}
	}
	if(gameLevel == 5){
		if (player->chances > 3){
			al_draw_bitmap(ranking->imageGameover, 0, 0, 0);
			loopQualifica(ev);
		}
	}
	return 1;

}