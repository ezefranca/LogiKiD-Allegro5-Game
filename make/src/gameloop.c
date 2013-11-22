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
ALLEGRO_SAMPLE *launch_song; //	= al_load_sample("./data/sound/music/Lunch.ogg");
ALLEGRO_SAMPLE *synth_song;// = al_load_sample("./data/sound/music/Syntheticity.ogg");

int i;

bool isDestroyed = false;
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
	LevelZero *levelZero = malloc(sizeof(LevelZero));
	LevelOne *levelOne;
	LevelDois *levelDois;
	LevelTres *levelTres;
	
	launch_song = al_load_sample("./data/sound/music/Lunch.ogg");
	synth_song = al_load_sample("./data/sound/music/Syntheticity.ogg");	
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
<<<<<<< HEAD
    Gates gate;
	ALLEGRO_BITMAP *fundo = al_load_bitmap("./data/levels/tutorial/tutorialbase.png");
	ALLEGRO_BITMAP *soundIconOn = al_load_bitmap("./data/images/icons/som.png");
	ALLEGRO_BITMAP *soundIconOff = al_load_bitmap("./data/images/icons/sem_som.png");
	ALLEGRO_BITMAP *soundIcon = soundIconOn;
	
=======
      Gates gate;
	ALLEGRO_BITMAP *fundo = SetBackGroundImage("./data/levels/tutorial/tutorialbase.png");
	ALLEGRO_BITMAP *soundIcon = al_load_bitmap("./data/images/icons/som.png");


>>>>>>> master
	createLevelZero(levelZero);
	logicLevelZero(&inputs[0], &complete, levelZero, player);
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

			/*case ALLEGRO_KEY_M:
				if(keys->keyUp == false && keys->keyDown == false && keys->keyLeft == false && keys->keyRight == false)
				{
					gate = MenuLoad(&ev, player);
				}
<<<<<<< HEAD
			break;*/			
=======

			break;
>>>>>>> master

			case ALLEGRO_KEY_SPACE:

				if(game.level == 0)
				{
					logicLevelZero(&inputs[0], &complete, levelZero, player);
				}
				if(game.level == 1)
				{
					logicLevelOne(&inputs[0], &inputs[1], &inputs[2], player);
					drawLogicLevelOne(inputs[0], inputs[1], inputs[2], levelOne, &complete);
				}
				if(game.level == 2)
				{
					logicLevelDois(&inputs[0], &inputs[1], &inputs[2], player);
					drawLogicLevelDois(inputs[0], inputs[1], inputs[2], levelDois, &complete);
				}
				if(game.level == 3)
				{
					logicLevelTres(&inputs[0], &inputs[1], &inputs[2], &inputs[3], player);
					drawLogicLevelTres(inputs[0], inputs[1], inputs[2], inputs[3], &complete, levelTres);
				}
<<<<<<< HEAD

=======
				if(game.level == 4)
				{

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
>>>>>>> master
			break;

			case ALLEGRO_KEY_ENTER:
				printf("%d\n", complete);
<<<<<<< HEAD
				if(complete){

					isDestroyed = false;
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

					if(game.level == 2){
						levelTres = malloc(sizeof(LevelTres));
						game.level = 3;
=======

				if(complete)
				{
					if(game.level == 2){
						levelTres = malloc(sizeof(LevelTres));
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
>>>>>>> master
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						initDrawGatesLevelTres(levelTres);
						drawLevelTres(levelTres);
						printf("Objetivo completo\n");
						complete = false;
						//free(levelDois);
					}

					if(game.level == 1){
						levelDois = malloc(sizeof(LevelDois));
						game.level = 2;
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						createLevelDois(levelDois);
						initDrawGatesLevelDois(levelDois);
						drawLogicLevelDois(inputs[0], inputs[1], inputs[2], levelDois, &complete);
						printf("Objetivo completo teste\n");
						complete = false;
					}
					if(game.level == 0){
						levelOne = malloc(sizeof(LevelOne));
						game.level = 1;
<<<<<<< HEAD
=======
						inputs[0] = false;
>>>>>>> master
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						createLevelOne(levelOne);
						initDrawGatesLevelOne(levelOne);
						drawLogicLevelOne(inputs[0], inputs[1], inputs[2], levelOne, &complete);
						printf("Objetivo completo %d\n", levelOne->teste);
						complete = false;
					}
				}
			}
		}

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
<<<<<<< HEAD
=======

>>>>>>> master
			if(!isCollidingGlobal(player, game.level))
			{
				movePlayer(keys, player);
			}
			redraw = true;
		}

	    //IMPLEMENTACAO MOUSE PARA TIRAR O SOM
          // Se o evento foi um clique do mouse
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
        	printf("CLICOU EM %d X %d Y \n", ev.mouse.x, ev.mouse.y);

            if (ev.mouse.x > 750 && ev.mouse.x < 780 && ev.mouse.y > 20 && ev.mouse.y < 50 )
            {
            	if (game.mute == 0){
                   	game.mute = 1;
                   	soundIcon = soundIconOn;
                   	musicPlayer(game.mute);
            	}
            	else
            	{
            	   	game.mute = 0;
            	   	soundIcon = soundIconOff;
            	   	musicPlayer(game.mute);
            	}
            }
        }

        //AQUI TODA ITERAÇÃO CARREGA IMAGEM. PRECISA CORRIGIR
		//Exibe fundo
		al_draw_bitmap(fundo, 0, 0, 0);
		//al_draw_bitmap(circuito, 0, 0 , 0);
		if (game.level == 0)
		{
		//	al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 600, 570, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelZero(levelZero);
		}
		if (game.level == 1)
		{
			//	al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 600, 570, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelOne(levelOne);
			if(isDestroyed == false)
			{
				destroyLevelZero(levelZero);
				free(levelZero);
				isDestroyed = true;
				printf("Liberou\n");
			}
		}
		if (game.level == 2)
		{
            printf("Nao sei\n");
            //al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 650, 10, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelDois(levelDois);
			if(isDestroyed == false)
			{
				destroyLevelOne(levelOne);
				free(levelOne);
				isDestroyed = true;
			}
		}
		if (game.level == 3)
		{
			al_draw_textf(game.fonte_menu, al_map_rgb(255, 255, 255), 650, 10, ALLEGRO_ALIGN_CENTRE, "Movimentos: %d" , levelTres->chances);
			drawLevelTres(levelTres);
			if(isDestroyed == false)
			{
				destroyLevelDois(levelDois);
				free(levelDois);
				isDestroyed = true;
			}
		}
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
*/	return false;
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
			game.song = launch_song;
			break;
			case 1:
			game.song = launch_song;
			break;
			case 2:
			game.song = synth_song;
			break;
			case 3:
			game.song = launch_song;
			break;
			case 4:
			game.song = synth_song;
			break;
			case 42:
			game.song = synth_song;
			break;
		}

		    game.songInstance = al_create_sample_instance(game.song);
                al_set_sample_instance_playmode(game.songInstance, ALLEGRO_PLAYMODE_LOOP);
                al_attach_sample_instance_to_mixer(game.songInstance, al_get_default_mixer());
                al_play_sample_instance(game.songInstance);

	}
}