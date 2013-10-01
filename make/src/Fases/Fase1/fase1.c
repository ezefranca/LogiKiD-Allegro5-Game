#include "fase1.h"
#include "../../comum.h"
#include "../../Player.h"
#include "../../ItensMenu.h"

ALLEGRO_BITMAP *SetBackGroundImage(const char *bk_path)
{
	return al_load_bitmap(bk_path);
}

bool isColliding(int boxPosX, int boxPosY, int boxWidth, int boxHeight, Player *player)
{	
	if ((player->state.x + player->image.frameWidth > boxPosX) &&
    	(player->state.x < boxPosX + boxWidth) && 
    	(player->state.y + player->image.frameHeight > boxPosY) &&
    	(player->state.y < boxPosY + boxHeight - (player->image.frameHeight/2)))
    {
        if(player->state.idleE == true) player->state.x += 1;
        if(player->state.idleD == true) player->state.x -= 1;
        if(player->state.idleC == true)	player->state.y += 1;
        if(player->state.idleB == true) player->state.y -= 1;
        return true;
    }
    else
    {
 		return false;
 	}
}

bool isCollidingGlobal(Player *player, int level){
	if(level == 1){
		if (isColliding(35, 12, 24, 80, player) ||
			isColliding(35, 154, 24, 80, player) ||
			isColliding(35, 288, 24, 80, player) ||
			isColliding(35, 445, 24, 80, player) ||
			isColliding(78, 25, 80, 60, player) ||
			isColliding(78, 165, 80, 60, player) ||
			isColliding(78, 303, 80, 60, player) ||
			isColliding(78, 452, 80, 60, player) ||
			isColliding(395, 0, 52, 408, player) ||
			isColliding(512, 380, 294, 35, player) ||
			isColliding(500, 277, 53, 74, player) ||
			isColliding(516, 150, 84, 58, player) ||
			isColliding(594, 235, 208, 50, player) ||
			isColliding(775, 412, 25, 36, player))
		{
			return true;
		}
		else return false;
	}
	else return false;
}


void GameLoop_Fase1(ALLEGRO_EVENT ev)
{
	bool sair = false;
	int level = 1;
		
	Keys *keys = malloc(sizeof(Keys));
	Player *player = malloc(sizeof(Player));
	
	
	/* TESTE MUSICA 
	ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *songInstance;
	//song = al_load_sample("song.ogg");
	song = al_load_sample("./data/sound/music/Lunch.ogg");
	songInstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
	al_play_sample_instance(songInstance);*/
						
	/* Adiciona a quantidade de portas logicas... */
	player->lGates.lgAND = 2;
	player->lGates.lgOR = 3;
	player->lGates.lgNAND = 0;
	player->lGates.lgNOR = 5;
	player->lGates.lgXOR = 1;
	player->lGates.lgXNOR = 10;
	player->lGates.lgNOT = 3;

	CreatePlayer(player, 213, 36);
	createKeys(keys);
    Gates gate;
	ALLEGRO_BITMAP *fundo = SetBackGroundImage("./data/levels/fase1/faseone_with_girl.png");
	
	//al_start_timer(game.timer);
	while(!sair)
	{
		al_wait_for_event(game.fila_eventos, &ev);
		setKeys(keys, player, &ev);
		
		if(player->state.x + player->image.frameWidth > 800) player->state.x = 800 - player->image.frameWidth;
		if(player->state.x < 0) player->state.x = 0;
		if(player->state.y + player->image.frameHeight > 600) player->state.y = 600 - player->image.frameHeight;
		if(player->state.y < 0) player->state.y = 0;

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)	sair = true;

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_M:
				if(keys->keyUp == false && keys->keyDown == false && keys->keyLeft == false && keys->keyRight == false)
				{
					gate = MenuLoad(&ev, player);	
				}
				break;
				
			case ALLEGRO_KEY_ENTER:
				if((player->state.x > 560 && player->state.x < 610) && (player->state.y > 372 && player->state.y < 382))
				{
					printf("Oi tudo bem?\n");
				}
				break;
			}
		}

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			//MUDANÇA DE TELA - level 1 para o 2
			if ((level == 1) && (player->state.x > 630 && player->state.x < 740 - player->image.frameWidth) && 
				(player->state.y + player->image.frameHeight / 2) > 500 && 
				(player->state.y + player->image.frameHeight / 2 < 600)) 
			{
				level = 2;
				player->state.x = 693;
				player->state.y = 30;
				fundo = SetBackGroundImage("./data/levels/fase1/faseone2.png");
				player->state.idleE = false;
				player->state.idleD = false;
				player->state.idleC = false;
				player->state.idleB = true;
				printf("ENTROU NA ESCADA \n");
			}
			//Mudança de tela - level 2 para o 1
			if ((level == 2) && (player->state.x > 667 && player->state.x < 780 - player->image.frameWidth) &&
				(player->state.y + player->image.frameHeight / 2) > 0 && 
				(player->state.y + player->image.frameHeight / 2 < 40))
			{
				level = 1;
				player->state.x = 632;
				player->state.y = 452;
				player->state.idleE = false;
				player->state.idleD = false;
				player->state.idleC = true;
				player->state.idleB = false;
				fundo = SetBackGroundImage("./data/levels/fase1/faseone_with_girl.png");
				printf("ENTROU NA ESCADA \n");
			}
			if(!isCollidingGlobal(player, level))
			{				
				movePlayer(keys, player);
			}
		}
		
		//Exibe fundo
		al_draw_bitmap(fundo, 0, 0, 0);
		
		ValidaMovimento(player);
		
		//Aqui exibimos qual a porta lógica escolhida. Se não houver mais portas, exibe "nao tem mais portas"
		//Está comentado pois ainda não está funcionando da forma correta
		/*switch(gate)
		{
		case NOT:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "NOT");
			break;
		case AND:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "AND");
			break;
		case OR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "OR");
			break;
		case NAND:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "NAND");
			break;
		case NOR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "NOR");
			break;
		case XOR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "XOR");
			break;
		case XNOR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "XNOR");
			break;
		default:
			if(gate == 66)
				al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 400, 240, ALLEGRO_ALIGN_CENTRE, "nao tem mais portas :(");
			break;	
		}*/
				
		al_flip_display();
		//al_clear_to_color(al_map_rgb(0,0,0));
	}
	//al_destroy_sample(song);
	//al_destroy_sample_instance(songInstance);
	//al_stop_sample_instance(songInstance);
	free(keys);
	free(player);
}
