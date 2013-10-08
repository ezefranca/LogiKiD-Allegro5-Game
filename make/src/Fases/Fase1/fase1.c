#include "fase1.h"
#include "../../comum.h"
#include "../../Player.h"
#include "../../ItensMenu.h"
#include "../../textBox.h"

ALLEGRO_BITMAP *SetBackGroundImage(const char *bk_path);
bool isColliding(int boxPosX, int boxPosY, int boxWidth, int boxHeight, Player *player);
bool isCollidingGlobal(Player *player, int level);	
void musicPlayer(int mute);

bool redraw = false;

void GameLoop_Fase1(ALLEGRO_EVENT ev)
{
	bool sair = false;
	Keys *keys = malloc(sizeof(Keys));
	Player *player = malloc(sizeof(Player));
	Dialogs *dialog = malloc(sizeof(Dialogs));	
	/* Adiciona a quantidade de portas logicas... */
	player->lGates.lgAND = 2;
	player->lGates.lgOR = 3;
	player->lGates.lgNAND = 0;
	player->lGates.lgNOR = 5;
	player->lGates.lgXOR = 1;
	player->lGates.lgXNOR = 10;
	player->lGates.lgNOT = 3;

	CreatePlayer(player, 213, 450);
	createKeys(keys);
	createDialogs(dialog);
    Gates gate;
	ALLEGRO_BITMAP *fundo = SetBackGroundImage("./data/levels/fase1/faseone_with_girl.png");
	ALLEGRO_BITMAP *soundIcon = al_load_bitmap("./data/images/icons/som.png");
	musicPlayer(game.mute);
	//al_start_timer(game.timer);
	while(!sair)
	{

		al_wait_for_event(game.fila_eventos, &ev);
		setKeys(keys, player, &ev);
		
		if(player->state.x + player->image.frameWidth > 800) player->state.x = 800 - player->image.frameWidth;
		if(player->state.x < 0) player->state.x = 0;
		if(player->state.y + player->image.frameHeight > 600) player->state.y = 600 - player->image.frameHeight;
		if(player->state.y < 0) player->state.y = 0;

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			sair = true;
			al_destroy_sample_instance(game.songInstance);
		}
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
				if(game.level == 1)
				{
					if((player->state.x > 560 && player->state.x < 610) && (player->state.y > 372 && player->state.y < 382))
					{
						printf("Oi tudo bem?\n");
						TextBoxLoad(&ev, dialog->menina_texto_1);
					}
				}
				if(game.level == 2)
				{
					if((player->state.x > 214 && player->state.x < 230) && (player->state.y > 265 && player->state.y < 326))
					{
						TextBoxLoad(&ev, dialog->computador_texto_1);
						printf("Acessando computador\n");
					}
					else
					{
						TextBoxLoad_matriz(&ev, dialog->computador_matriz);
						printf("Acessando computador\n");
					}	
				}	
				break;
			}
		}

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			//MUDANÇA DE TELA - level 1 para o 2
			if ((game.level == 1) && (player->state.x > 630 && player->state.x < 740 - player->image.frameWidth) && 
				(player->state.y + player->image.frameHeight / 2) > 500 && 
				(player->state.y + player->image.frameHeight / 2 < 600)) 
			{
				game.level = 2;
				player->state.x = 284;
				player->state.y = 40;
				//AQUI VAI UM FADE IN FADE OUT
				fundo = SetBackGroundImage("./data/levels/fase2/fundo-fase2.png");
				player->state.idleE = false;
				player->state.idleD = false;
				player->state.idleC = false;
				player->state.idleB = true;
				printf("ENTROU NA ESCADA X \n");
			}
			//Mudança de tela - level 2 para o 1
			if ((game.level == 2) && (player->state.x > 262 && player->state.x < 354 - player->image.frameWidth) &&
				(player->state.y + player->image.frameHeight / 2) > 0 && 
				(player->state.y + player->image.frameHeight / 2 < 40))
			{
				game.level = 1;
				player->state.x = 632;
				player->state.y = 452;
				//AQUI VAI UM FADE IN FADE OUT
				fundo = SetBackGroundImage("./data/levels/fase1/faseone_with_girl.png");
				player->state.idleE = false;
				player->state.idleD = false;
				player->state.idleC = true;
				player->state.idleB = false;
				printf("ENTROU NA ESCADA \n");
			}
			if(!isCollidingGlobal(player, game.level))
			{				
				movePlayer(keys, player);
			}
			redraw = true;
		}

	    //IMPLEMENTACAO MOUSE PARA TIRAR O SOM
        // Se o evento foi de movimentação do mouse
        /*if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
        	printf("%d X %d Y \n", ev.mouse.x, ev.mouse.y);
            // Verificamos se ele está sobre a região do botao de mute
            if (ev.mouse.x > 750 && ev.mouse.x <= 780 && ev.mouse.y > 20 && ev.mouse.y < 50 )
            {
                //em cima do mute
            }
            else
            {
                //fora do mute
            }
        }*/
        // Ou se o evento foi um clique do mouse
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
        	printf("CLICOU EM %d X %d Y \n", ev.mouse.x, ev.mouse.y);
           
            if (ev.mouse.x > 750 && ev.mouse.x < 780 && ev.mouse.y > 20 && ev.mouse.y < 50 )
            {
            	if (game.mute == 0){
                   	game.mute = 1;
                   	soundIcon = al_load_bitmap("./data/images/icons/som.png");
                   	musicPlayer(game.mute);
            	}
            	else
            	{
            	   	game.mute = 0;
            	   	soundIcon = al_load_bitmap("./data/images/icons/sem_som.png");
            	   	musicPlayer(game.mute);
            	}

            }
        }
		
		//Exibe fundo
		al_draw_bitmap(fundo, 0, 0, 0);
		ValidaMovimento(player);
		al_draw_bitmap(soundIcon, 750, 20, 0);
		
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
		
		if(redraw && al_is_event_queue_empty(game.fila_eventos)) {
        	redraw = false; 
        	al_flip_display();
      	}
	}
	free(keys);
	free(player);
	free(dialog);
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
        if(player->state.idleC == true) player->state.y += 1;
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
		if (isColliding(35, 12, 24, 80, player)    ||
			isColliding(35, 154, 24, 80, player)   ||
			isColliding(35, 288, 24, 80, player)   ||
			isColliding(35, 445, 24, 80, player)   ||
			isColliding(78, 25, 80, 60, player)    ||
			isColliding(78, 165, 80, 60, player)   ||
			isColliding(78, 303, 80, 60, player)   ||
			isColliding(78, 452, 80, 60, player)   ||
			isColliding(395, 0, 52, 408, player)   ||
			isColliding(512, 380, 294, 35, player) ||
			isColliding(500, 277, 53, 74, player)  ||
			isColliding(516, 150, 84, 58, player)  ||
			isColliding(594, 235, 208, 50, player) ||
			isColliding(775, 412, 25, 36, player))
		{
			return true;
		}
		else return false;
	}
	if(level == 2)
	{
		if (isColliding(421, 157, 92, 61, player)   ||
			isColliding(518, 314, 92, 61, player)   ||
			isColliding(741, 157, 92, 61, player)   ||
			isColliding(0, 0, 195, 220, player)     ||
			isColliding(195, 0, 66, 90, player)     ||
			isColliding(357, 0, 177, 90, player)    ||
			isColliding(0, 415, 505, 600, player)   ||
			isColliding(357, 0, 177, 90, player)    ||
			isColliding(510, 490, 290, 110, player) ||
			isColliding(0, 283, 220, 100, player))
		{
			return true;
		}
		else return false;
	}
	else return false;
}

void musicPlayer(int mute){

	if (mute == 0){
		printf("***************MUTE*****************\n");
	    al_destroy_sample_instance(game.songInstance);
	}
	else if(mute == 1){
		printf("***************PLAY*****************\n");
		game.song = al_load_sample("./data/sound/music/Lunch.ogg");
		game.songInstance = al_create_sample_instance(game.song);
		al_set_sample_instance_playmode(game.songInstance, ALLEGRO_PLAYMODE_LOOP);
		al_attach_sample_instance_to_mixer(game.songInstance, al_get_default_mixer());
		al_play_sample_instance(game.songInstance);
	}
}

ALLEGRO_BITMAP *SetBackGroundImage(const char *bk_path)
{
	return al_load_bitmap(bk_path);
}