#include "gameloop.h"
#include "comum.h"
#include "Player.h"
#include "ItensMenu.h"
#include "textBox.h"
#include "../src/Fases/Fase0/fase0.h"
#include "../src/Fases/Fase1/fase1.h"
#include "../src/Fases/Fase2/fase2.h"
#include "../src/Fases/Fase3/fase3.h"

ALLEGRO_BITMAP *SetBackGroundImage(const char *bk_path);
bool isColliding(int boxPosX, int boxPosY, int boxWidth, int boxHeight, Player *player);
bool isCollidingGlobal(Player *player, int level);
void musicPlayer(int mute);

int i;
bool redraw = false;
bool complete = false;
//bool drawCirc = false;
ALLEGRO_BITMAP *textBox;
bool inputs[8] = {false, false, false, false, false, false, false, false};

void GameLoop_Fase1(ALLEGRO_EVENT ev)
{
	game.level = 0;
	bool sair = false;
	Keys *keys = malloc(sizeof(Keys));
	Player *player = malloc(sizeof(Player));
	Dialogs *dialog = malloc(sizeof(Dialogs));
	LevelOne *levelOne = malloc(sizeof(LevelOne));
	LevelZero *levelZero = malloc(sizeof(LevelZero));
	LevelDois *levelDois = malloc(sizeof(LevelDois));
	LevelTres *levelTres = malloc(sizeof(LevelTres));

	/* Adiciona a quantidade de portas logicas... */
	player->lGates.lgAND = 2;
	player->lGates.lgOR = 3;
	player->lGates.lgNAND = 0;
	player->lGates.lgNOR = 5;
	player->lGates.lgXOR = 1;
	player->lGates.lgXNOR = 10;
	player->lGates.lgNOT = 3;

	//initDrawGatesLevelOne(levelOne);

	CreatePlayer(player, 213, 450);
	createKeys(keys);
	createDialogs(dialog);
      Gates gate;
	ALLEGRO_BITMAP *fundo = SetBackGroundImage("./data/levels/tutorial/tutorialbase.png");
	ALLEGRO_BITMAP *soundIcon = al_load_bitmap("./data/images/icons/som.png");
	logicLevelZero(inputs[0], levelZero);
	//ALLEGRO_BITMAP *circuito = logicLevelOne(inputs[0], inputs[1], circuito);
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

		if((ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
		{
			//drawCirc = false;
			sair = true;
			game.level = 1;
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

			case ALLEGRO_KEY_1:
				game.level = 1;
				//drawCirc = false;
				musicPlayer(game.mute);
				fundo = SetBackGroundImage("./data/levels/fase1/faseone_with_girl.png");
			break;

			case ALLEGRO_KEY_2:
				game.level = 2;
			//	drawCirc = false;
				musicPlayer(game.mute);
				fundo = SetBackGroundImage("./data/levels/fase2/fundo-fase2.png");
			break;

			case ALLEGRO_KEY_3:
				game.level = 3;
				initDrawGatesLevelOne(levelOne);
				musicPlayer(game.mute);
				//drawCirc = true;
				fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
				drawLogicLevelOne(inputs[0], inputs[1], inputs[2], levelOne);
			break;

			case ALLEGRO_KEY_4:
				game.level = 4;
				//fundo = al_load_bitmap("./data/levels/fase0/faseruavermelho.png");
				musicPlayer(game.mute);
				fundo = SetBackGroundImage("./data/levels/fase0/faseruavermelho.png");
				//drawCirc = false;
			break;

			/*case ALLEGRO_KEY_5:
				game.level = 0;
				drawCirc = true;
				musicPlayer(game.mute);
				initDrawGatesLevelZero(levelZero);
				fundo = SetBackGroundImage("./data/levels/fase0/teste.png");
				logicLevelZero(inputs[0], inputs[1], levelZero);
			break;

			/*case ALLEGRO_KEY_6:
				game.level = 0;
				drawCirc = true;
				musicPlayer(game.mute);
				initDrawGatesLevelZero(levelTres);
				fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
				logicLevelZero(inputs[0], inputs[1], levelTres);
			break;*/

			case ALLEGRO_KEY_SPACE:

				if(game.level == 0)
				{
					if ((player->state.x > 200 && player->state.x < 318) && (player->state.y > 185 && player->state.y < 275))
					{
						if(inputs[0] == false)
						{
							inputs[0] = true;
							complete = true;
						}
						else inputs[0] = false;
						printf("Mudando porta 1\n");
					}
					logicLevelZero(inputs[0], levelZero);
				}


				if(game.level == 1)
				{
					if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 65 && player->state.y < 154))
					{
						if(inputs[0] == false){
							inputs[0] = true;
							printf("False para true\n");
							complete = true;
						}
						else{
							inputs[0] = false;
							printf("True para false\n");
						}
					}
					if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 155 && player->state.y < 238))
					{
						if(inputs[1] == false){
							inputs[1] = true;
							printf("False para true\n");
						}
						else{
							inputs[1] = false;
							printf("True para false\n");
						}
					}
					if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 254 && player->state.y < 338))
					{
						if(inputs[2] == false){
							inputs[2] = true;
							printf("False para true\n");
						}
						else{
							inputs[2] = false;
							printf("True para false\n");
						}
					}
					drawLogicLevelOne(inputs[0], inputs[1], inputs[2], levelOne);
				}
				if(game.level == 2)
				{
					if((player->state.x > 73 && player->state.x < 198) && (player->state.y > 33 && player->state.y < 122))
					{
						if(inputs[0] == false){
							inputs[0] = true;
							printf("False para true\n");
							complete = true;
						}
						else{
							inputs[0] = false;
							printf("True para false\n");
						}
					}
					if((player->state.x > 73 && player->state.x < 198) && (player->state.y > 123 && player->state.y < 206))
					{
						if(inputs[1] == false){
							inputs[1] = true;
							printf("False para true\n");
						}
						else{
							inputs[1] = false;
							printf("True para false\n");
						}
					}
					if((player->state.x > 73 && player->state.x < 198) && (player->state.y > 222 && player->state.y < 306))
					{
						if(inputs[2] == false){
							inputs[2] = true;
							printf("False para true\n");
						}
						else{
							inputs[2] = false;
							printf("True para false\n");
						}
					}
					drawLogicLevelDois(inputs[0], inputs[1], inputs[2], levelDois);
				}
				if(game.level == 3)
				{
					if((player->state.x > 0 && player->state.x < 20) && (player->state.y > 40 && player->state.y < 70))
					{
						if(inputs[0] == false){
							inputs[0] = true;
							printf("False para true\n");
							complete = true;
						}
						else{
							inputs[0] = false;
							printf("True para false\n");
						}
					}
					if ((player->state.y > 100 && player->state.y < 120) && (player->state.x > 0 && player->state.x < 20))
					{
						if(inputs[1] == false){
							inputs[1] = true;
							printf("False para true\n");
						}
						else{
							inputs[1] = false;
							printf("True para false\n");
						}
					}
					if ((player->state.y > 200 && player->state.y < 220) && (player->state.x > 0 && player->state.x < 20))
					{
						if(inputs[2] == false){
							inputs[2] = true;
							printf("False para true\n");
						}
						else{
							inputs[2] = false;
							printf("True para false\n");
						}
					}
					if ((player->state.y > 260 && player->state.y < 280) && (player->state.x > 0 && player->state.x < 20))
					{
						if(inputs[3] == false){
							inputs[3] = true;
							printf("False para true\n");
						}
						else{
							inputs[3] = false;
							printf("True para false\n");
						}
					}
					drawLogicLevelTres(inputs[0], inputs[1], inputs[2], inputs[3], levelTres);
				}

				if(game.level == 4)
				{
					//if((player->state.x > 214 && player->state.x < 230) && (player->state.y > 265 && player->state.y < 326))
					//{
						TextBoxLoad(&ev, dialog->computador_texto_1);
						printf("Eu estou na  rua\n");
					//}
				}

				if(game.level == 42)
				{
						textBox = al_load_bitmap("data/images/textbox.png");
						al_draw_bitmap(textBox, 0, 450, 0);
						for(i = 0; i < 2; i++)
						{
							TextBoxLoad_matriz(&ev, dialog->texto_generico[i], 472 + i*25);
						}
				}
			break;

			case ALLEGRO_KEY_ENTER:
				if(complete){
					if(game.level == 2){
						game.level = 3;
						player->state.x = 350;
						player->state.y = 20;
						player->state.idleE = false;
						player->state.idleD = false;
						player->state.idleC = false;
						player->state.idleB = true;
						inputs[0] = true;
						inputs[1] = false;
						inputs[2] = false;
						inputs[3] = false;
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						initDrawGatesLevelTres(levelTres);
						drawLevelTres(levelTres);
						printf("Objetivo completo\n");
						complete = false;
					}
					if(game.level == 1){
						game.level = 2;
						player->state.x = 350;
						player->state.y = 20;
						player->state.idleE = false;
						player->state.idleD = false;
						player->state.idleC = false;
						player->state.idleB = true;
						inputs[0] = false;
						inputs[1] = false;
						inputs[2] = false;
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						initDrawGatesLevelDois(levelDois);
						drawLogicLevelDois(inputs[0], inputs[1], inputs[2], levelDois);
						printf("Objetivo completo\n");
						complete = false;
					}
					if(game.level == 0){
						game.level = 1;
						player->state.x = 350;
						player->state.y = 20;
						player->state.idleE = false;
						player->state.idleD = false;
						player->state.idleC = false;
						player->state.idleB = true;
						inputs[0] = false;
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						initDrawGatesLevelOne(levelOne);
						drawLogicLevelOne(inputs[0], inputs[1], inputs[2], levelOne);
						printf("Objetivo completo\n");
						complete = false;
					}

				}

			}
		}

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			//MUDANÇA DE TELA - level 2 para o 3
			/*if ((game.level == 1) && (player->state.x > 630 && player->state.x < 740 - player->image.frameWidth) &&
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
			}*/
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

        //AQUI TODA ITERAÇÃO CARREGA IMAGEM. PRECISA CORRIGIR
		//Exibe fundo
		al_draw_bitmap(fundo, 0, 0, 0);
		//al_draw_bitmap(circuito, 0, 0 , 0);
		if (game.level == 0){
		//	al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 600, 570, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelZero(levelZero);
		}
		if (game.level == 1){
		//	al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 600, 570, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelOne(levelOne);
		}
		if (game.level == 2){
                    al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 650, 10, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelDois(levelDois);
		}
		if (game.level == 3) {
			if (levelTres->chances == 0){
				sair = true;
				game.level = 1;
				al_destroy_sample_instance(game.songInstance);
			}
			al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 650, 10, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelTres(levelTres);
		}
		//drawLevelOne(levelOne);
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
	free(levelZero);
	free(levelOne);
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
	if(level == 0)
	{
		if(isColliding(261, 267, 56, 40, player)) return true;
		else return false;
	}

	if(level == 1){
		if (isColliding(165, 150, 55, 35, player)    ||
			isColliding(165, 238, 55, 35, player)   ||
			isColliding(165, 335, 55, 35, player))
		{
			return true;
		}
		else return false;
	}
	if(level == 2)
	{
		if (isColliding(133, 118, 55, 35, player)    ||
			isColliding(133, 202, 55, 35, player)   ||
			isColliding(133, 302, 55, 35, player))
		{
			return true;
		}
		else return false;
	}
	//if(level == 3)
		/*
	   	{
	    if (isColliding(98, 108, 60, 42, player)   ||
	    	isColliding(98, 206, 60, 42, player)   ||
	    	isColliding(98, 301, 60, 42, player)   ||
	    	isColliding(450, 130, 64, 64, player)   ||
	      isColliding(450, 291, 64, 64, player))
	    {
	    	return true;
	    }
	    else return false;
	}
	else return false;
*/
}

void musicPlayer(int mute){
	if (mute == 0){
		printf("***************MUTE*****************\n");
	    al_destroy_sample_instance(game.songInstance);
	    game.songInstance = NULL;
	    return;
	} else if(mute == 1){
			if (game.songInstance != NULL)
			al_destroy_sample_instance(game.songInstance);
		printf("***************PLAY*****************\n");
		switch (game.level){
			case 0:
			game.song = al_load_sample("./data/sound/music/Lunch.ogg");
			break;
			case 1:
			game.song = al_load_sample("./data/sound/music/Lunch.ogg");
			break;
			case 2:
			game.song = al_load_sample("./data/sound/music/Syntheticity.ogg");
			break;
			case 3:
			game.song = al_load_sample("./data/sound/music/Lunch.ogg");
			break;
			case 4:
			game.song = al_load_sample("./data/sound/music/Syntheticity.ogg");
			break;
			case 42:
			game.song = al_load_sample("./data/sound/music/Syntheticity.ogg");
			break;
		}

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