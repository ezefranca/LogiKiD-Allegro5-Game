#include "Player.h"
#include "comum.h"
#include "pontuacao.h"
#include <string.h>

Ranked *ranking;

void criaQualificacao(Ranked *ranking) {
	ranking->imageExcelente =  al_load_bitmap("./data/levels/menu/EXCELENTE.png");
	ranking->imageBom = al_load_bitmap("./data/levels/menu/MUITOBOM.png");
	ranking->imageRegular= al_load_bitmap("./data/levels/menu/REGULAR.png");
	ranking->somExcelente = al_load_sample("./data/sound/menu_open.wav");
	ranking->somBom = al_load_sample("./data/sound/menu_open.wav");
	ranking->somRegular = al_load_sample("./data/sound/menu_open.wav");
}

void loopQualifica(ALLEGRO_EVENT *ev){
	bool sair = false;
	al_flip_display();
	while(!sair)
	{
		printf("passou\n");
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
	if(gameLevel == 4){
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
	if(gameLevel == 5){
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


	return 1;

}