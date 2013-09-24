#include "Player.h"
#include "comum.h"
#include "ItensMenu.h"

typedef struct 
{
	int itmSelX, itmSelY;
	int currGate;
	
	ALLEGRO_BITMAP *ImgMenu;
	ALLEGRO_BITMAP *and_gate;
	ALLEGRO_BITMAP *or_gate;
	ALLEGRO_BITMAP *nand_gate;
	ALLEGRO_BITMAP *nor_gate;
	ALLEGRO_BITMAP *xor_gate;
	ALLEGRO_BITMAP *xnor_gate;
	ALLEGRO_BITMAP *not_gate;
	ALLEGRO_BITMAP *itmSelec;
	
	ALLEGRO_SAMPLE *menuSoundOpen;
}lgImages;

char *itoa(int x)
{
	if(x == 0)
		return "0";
	else
	{
		int s = x<=0 ? 1 : 0; 
		size_t len = (size_t)ceil(log10(abs(x)));
		char *str = (char *)malloc(len+s + 1);

		sprintf(str, "%i", x);

		return str;
	}
}

void mk_up(lgImages *lgDados)
{
	if(lgDados->itmSelY == 460)
	{
		lgDados->itmSelY = 525;
		lgDados->currGate += 4;
	}
	else
	{
		lgDados->currGate -= 4;
		lgDados->itmSelY -= 65;
	}
			
	if(lgDados->itmSelX == 450)
	{
		lgDados->itmSelX = 350;
		lgDados->currGate = 6;
	}
}

void mk_down(lgImages *lgDados)
{
	if(lgDados->itmSelY == 525)
	{
		lgDados->itmSelY = 460;
		lgDados->currGate -= 4;
	}
	else
	{
		lgDados->itmSelY += 65;
		lgDados->currGate += 4;
	}
					
	if(lgDados->itmSelX == 450)
	{
		lgDados->itmSelX = 350;
		lgDados->currGate = 6;
	}
}

void mk_right(lgImages *lgDados)
{
	if(lgDados->itmSelX == 450)
	{
		lgDados->itmSelX = 150;
		lgDados->currGate = 0;
	}
	else
	{
		lgDados->itmSelX += 100;
		lgDados->currGate += 1;
	}
					
	if(lgDados->itmSelX == 450 && lgDados->itmSelY == 525)
	{
		lgDados->itmSelX = 150;
		lgDados->currGate = 4;
	}
}

void mk_left(lgImages *lgDados)
{
	if(lgDados->itmSelX == 150)
	{
		lgDados->itmSelX = 450;
		lgDados->currGate = 3;
	}
	else	
	{
		lgDados->itmSelX -= 100;
		lgDados->currGate -= 1;
	}
				
	if(lgDados->itmSelX == 450 && lgDados->itmSelY == 525)
	{
		lgDados->itmSelX = 350;
		lgDados->currGate = 6;
	}	
}

void DrawImages(lgImages *lgDados, Player *player)
{
	al_draw_bitmap(lgDados->ImgMenu, 150, 460, 0);
		
	// draw the item selector...
	al_draw_bitmap(lgDados->itmSelec, lgDados->itmSelX, lgDados->itmSelY, 0);
		
	// show gates and the gate count...
	al_draw_bitmap(lgDados->and_gate, 150, 460, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 197, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgAND));
		
	al_draw_bitmap(lgDados->or_gate, 250, 460, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 297, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgOR));
		
	al_draw_bitmap(lgDados->nand_gate, 350, 460, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 397, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgNAND));
		
	al_draw_bitmap(lgDados->nor_gate, 450, 460, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 497, 472, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgNOR));
		
	// next line...
	al_draw_bitmap(lgDados->xor_gate, 150, 525, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 197, 537, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgXOR));
		
	al_draw_bitmap(lgDados->xnor_gate, 250, 525, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 297, 537, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgXNOR));
		
	al_draw_bitmap(lgDados->not_gate, 350, 525, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 397, 537, ALLEGRO_ALIGN_CENTER, itoa(player->lGates.lgNOT));
}

Gates GetGate(lgImages *lgDados, Player *player)
{
	switch(lgDados->currGate)
	{
	case AND:
		if(player->lGates.lgAND > 0)
			player->lGates.lgAND -= 1;
		else
			lgDados->currGate = 66;
		break;
	case OR:
		if(player->lGates.lgOR > 0)
			player->lGates.lgOR -= 1;
		else
			lgDados->currGate = 66;
		break;
	case NAND:
		if(player->lGates.lgNAND > 0)
			player->lGates.lgNAND -= 1;
		else
			lgDados->currGate = 66;
		break;
	case NOR:
		if(player->lGates.lgNOR > 0)
			player->lGates.lgNOR -= 1;
		else
			lgDados->currGate = 66;
		break;
	case XOR:
		if(player->lGates.lgXOR > 0)
			player->lGates.lgXOR -= 1;
		else
			lgDados->currGate = 66;
		break;
	case XNOR:
		if(player->lGates.lgXNOR > 0)
			player->lGates.lgXNOR -= 1;
		else
			lgDados->currGate = 66;
		break;
	case NOT:
		if(player->lGates.lgNOT > 0)
			player->lGates.lgNOT -= 1;
		else
			lgDados->currGate = 66;
		break;
	}
	
	return lgDados->currGate;
}

Gates MenuLoad(ALLEGRO_EVENT *ev, Player *player)
{
	bool sair = false;
	
	lgImages *lgDados = malloc(sizeof(lgImages));		
	lgDados->itmSelX = 150;
	lgDados->itmSelY = 460;
	lgDados->currGate = 0;
	
	lgDados->ImgMenu = al_load_bitmap("data/images/Player/PlayerMenu.png");
	lgDados->and_gate = al_load_bitmap("data/images/Gates/AND.png");
	lgDados->or_gate = al_load_bitmap("data/images/Gates/OR.png");
	lgDados->nand_gate = al_load_bitmap("data/images/Gates/NAND.png");
	lgDados->nor_gate = al_load_bitmap("data/images/Gates/NOR.png");
	lgDados->xor_gate = al_load_bitmap("data/images/Gates/XOR.png");
	lgDados->xnor_gate = al_load_bitmap("data/images/Gates/XNOR.png");
	lgDados->not_gate = al_load_bitmap("data/images/Gates/NOT.png");
	lgDados->itmSelec = al_load_bitmap("data/images/Gates/ItemSelector.png");
	
	lgDados->menuSoundOpen = al_load_sample("./data/sound/menu_open.wav");
	al_play_sample(lgDados->menuSoundOpen, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
	
	al_rest(0.1); // causa um micro delay, apenas para sincronizar o audio...

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
				al_play_sample(lgDados->menuSoundOpen, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
				sair = true;
				break;
			case ALLEGRO_KEY_ENTER:
				al_play_sample(lgDados->menuSoundOpen, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
				return GetGate(lgDados, player);			
				break;
			case ALLEGRO_KEY_LEFT:
				mk_left(lgDados);
				break;
			case ALLEGRO_KEY_RIGHT:			
				mk_right(lgDados);
				break;
			case ALLEGRO_KEY_UP:
				mk_up(lgDados);
				break;
			case ALLEGRO_KEY_DOWN:
				mk_down(lgDados);
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