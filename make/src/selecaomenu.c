#include "Player.h"
#include "comum.h"
#include "config.h"
#include "pontuacao.h"
#include "StartMenu.h"
#include "gameloop.h"
#include "selecaomenu.h"
#include <string.h>




void menuSelecaox()
{
	ALLEGRO_BITMAP *menufundo = al_load_bitmap("./data/levels/selecao.png");
	al_draw_bitmap(menufundo, 0, 0, 0);
	al_draw_text(game.fonte, al_map_rgb(255,  0,  0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, get_idioma("Choose your character"));
	//al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 152, ALLEGRO_ALIGN_CENTRE, "Sair");

}


void mk_right(lgImages *lgDados)
{
	al_draw_bitmap(lgDados->Seletor2,  lgDados->itmSelX,  lgDados->itmSelY, 0);
	if(lgDados->itmSelX == 490){
		lgDados->itmSelX = 70;
	} else{
		lgDados->itmSelX += 70;
	}
}

void mk_left(lgImages *lgDados)
{
	al_draw_bitmap(lgDados->Seletor2,  lgDados->itmSelX,  lgDados->itmSelY, 0);
	if(lgDados->itmSelX == 70)
	{
		lgDados->itmSelX = 490;
	}
	else
	{

		lgDados->itmSelX -= 70;
	}
}

void DrawImages(lgImages *lgDados, Player *player)
{
	printf("ENTROU NO DrawImages");
//	al_draw_bitmap(lgDados->ImagemMenu, 150, 460, 0);
	printf("printou menu");
	// draw the item selector...
	al_draw_bitmap(lgDados->Seletor,  lgDados->itmSelX,  lgDados->itmSelY, 0);
	printf("printou seletor");
	// show gates and the gate count...
	al_draw_bitmap(lgDados->PER1, 70, 460, 0);
		printf("printou per 1");
	//al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 197, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgAND));

	al_draw_bitmap(lgDados->PER2, 140, 460, 0);
		printf("2");
	//al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 297, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgOR));

	al_draw_bitmap(lgDados->PER3, 210, 460, 0);
		printf("3");
	//al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 397, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgNAND));

	al_draw_bitmap(lgDados->PER4, 280, 460, 0);
		printf("4");
	//al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 497, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgNOR));

	// next line...
	al_draw_bitmap(lgDados->PER5, 350, 460, 0);
		printf("5");
	//al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 197, 537, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgXOR));

	al_draw_bitmap(lgDados->PER6, 420, 460, 0);
		printf("6");
	//al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 297, 537, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgXNOR));

	al_draw_bitmap(lgDados->PER7, 490, 460, 0);
		printf("7\n");
	//al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 397, 537, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgNOT));
}

Personagem GetPersonagem(lgImages *lgDados, Player *player)
{
	Personagem person;
	switch(lgDados->itmSelX)
	{
	case 70:
		person = 1;
		break;
	case 140:
		person = 2;
		break;
	case 210:
		person = 3;
		break;
	case 280:
		person = 4;
		break;
	case 350:
		person = 5;
		break;
	case 420:
		person = 6;
		break;
	case 490:
		person = 7;
		break;
	}
	return person;
}

Personagem MenuLoadPerson(ALLEGRO_EVENT *ev, Player *player)
{
	bool sair = false;

	lgImages *lgDados = malloc(sizeof(lgImages));
	lgDados->itmSelX = 70;
	lgDados->itmSelY = 460;
	lgDados->currGate = 0;
	printf("----\n");
	lgDados->ImagemMenu = al_load_bitmap("data/levels/selecao.png");
	lgDados->PER1 = al_load_bitmap("data/images/Personagem/PER1.png");
	printf("1\n");
	lgDados->PER2 = al_load_bitmap("data/images/Personagem/PER2.png");
	printf("2\n");
	lgDados->PER3 = al_load_bitmap("data/images/Personagem/PER3.png");
	printf("3\n");
	lgDados->PER4 = al_load_bitmap("data/images/Personagem/PER4.png");
	printf("4\n");
	lgDados->PER5 = al_load_bitmap("data/images/Personagem/PER5.png");
	printf("5\n");
	lgDados->PER6 = al_load_bitmap("data/images/Personagem/PER6.png");
	printf("6\n");
	lgDados->PER7 = al_load_bitmap("data/images/Personagem/PER7.png");
	printf("passou\n");
	lgDados->Seletor = al_load_bitmap("data/images/Personagem/ItemSelector.png");
	lgDados->Seletor2 = al_load_bitmap("data/images/Personagem/ItemSelector2.png");
       printf("seletor\n");
	lgDados->menuSoundOpen = al_load_sample("./data/sound/menu_open.wav");
	al_play_sample(lgDados->menuSoundOpen, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);

	al_rest(0.1); // causa um micro delay, apenas para sincronizar o audio...

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
				al_play_sample(lgDados->menuSoundOpen, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
				sair = true;
				break;
			case ALLEGRO_KEY_ENTER:
				al_play_sample(lgDados->menuSoundOpen, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
				return GetPersonagem(lgDados, player);
				break;
			case ALLEGRO_KEY_LEFT:
				mk_left(lgDados);
				break;
			case ALLEGRO_KEY_RIGHT:
				mk_right(lgDados);
				break;
			case ALLEGRO_KEY_M:
				al_play_sample(lgDados->menuSoundOpen, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
				sair=true;
				break;
			}
		}

		DrawImages(lgDados, player);

		al_flip_display();
	}

	free(lgDados);

	return 99;
}
