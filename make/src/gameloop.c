#include "gameloop.h"
#include "comum.h"
#include "Player.h"
#include "ItensMenu.h"
#include "textBox.h"
#include "pontuacao.h"
#include "config.h"
#include "selecaomenu.h"
#include "../src/Fases/Fase0/fase0.h"
#include "../src/Fases/Fase1/fase1.h"
#include "../src/Fases/Fase2/fase2.h"
#include "../src/Fases/Fase3/fase3.h"
#include "../src/Fases/Fase4/fase4.h"
#include "../src/Fases/Fase5/fase5.h"

ALLEGRO_BITMAP *SetBackGroundImage(const char *bk_path);
bool isColliding(int boxPosX, int boxPosY, int boxWidth, int boxHeight, Player *player);
bool isCollidingGlobal(Player *player, int level);
void musicPlayer(int mute);
void objectiveComplete();
void showObjective(int level);
ALLEGRO_SAMPLE *launch_song; //	= al_load_sample("./data/sound/music/Lunch.ogg");
ALLEGRO_SAMPLE *synth_song;// = al_load_sample("./data/sound/music/Syntheticity.ogg");

int i;

bool isDestroyed = false;
bool redraw = false;
bool complete = false;
ALLEGRO_BITMAP *textBox;
bool inputs[8] = {false, false, false, false, false, false, false, false};

void GameLoop(ALLEGRO_EVENT ev)
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
	LevelQuatro *levelQuatro;
	LevelCinco *levelCinco;

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

	Personagem person;
	person = MenuLoadPerson(&ev, player);

	CreatePlayer(player, 213, 450, person);
	createKeys(keys);
	createDialogs(dialog);

    //Gates gate;

	ALLEGRO_BITMAP *fundo = al_load_bitmap("./data/levels/tutorial/tutorialbase.png");
	ALLEGRO_BITMAP *soundIconOn = al_load_bitmap("./data/images/icons/som.png");
	ALLEGRO_BITMAP *soundIconOff = al_load_bitmap("./data/images/icons/sem_som.png");
	ALLEGRO_BITMAP *soundIcon = soundIconOn;

	createLevelZero(levelZero, player);
	logicLevelZero(&inputs[0], &complete, levelZero, player);

	TextBoxLoad(&ev, get_idioma("Welcome to LogiKid"));
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
			sair = true;
			salva_config_user("data/config/user.conf");
			//limpa_config();
			//limpa_idioma();
			//limpa_config_user();
			al_destroy_sample_instance(game.songInstance);
		}
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
					sair = true;
				break;

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
					if(game.level == 4)
					{
						logicLevelQuatro(&inputs[0], &inputs[1], &inputs[2], player);
						drawLogicLevelQuatro(inputs[0], inputs[1], inputs[2], levelQuatro, &complete);
					}
					if(game.level == 5)
					{
						logicLevelCinco(&inputs[0], &inputs[1], player);
						drawLogicLevelCinco(inputs[0], inputs[1], levelCinco, &complete);
					}
				break;

				case ALLEGRO_KEY_ENTER:
					printf("%d\n", complete);

					if(complete)
					{
						musicPlayer(0);
						qualificaJogador (player, game.level, &ev);
						musicPlayer(1);
						isDestroyed = false;
						player->state.x = 350;
						player->state.y = 20;
						player->state.idleE = false;
						player->state.idleD = false;
						player->state.idleC = false;
						player->state.idleB = true;
						inputs[0] = false;
						inputs[1] = false;
						inputs[2] = false;
						inputs[3] = false;
					if(game.level == 5)
					{
						sair = true;
						printf("sair = true");
					}
					if(game.level == 4)
					{
						levelCinco = malloc(sizeof(LevelCinco));
						game.level = 5;
						createLevelCinco(levelCinco, player);
						initDrawGatesLevelCinco(levelCinco);
						drawLogicLevelCinco(inputs[0], inputs[1], levelCinco, &complete);
						printf("Objetivo completo\n");
						complete = false;
					}
					if(game.level == 3)
					{
						levelQuatro = malloc(sizeof(LevelQuatro));
						game.level = 4;
						inputs[1] = true;
						createLevelQuatro(levelQuatro, player);
						initDrawGatesLevelQuatro(levelQuatro);
						drawLogicLevelQuatro(inputs[0], inputs[1], inputs[2], levelQuatro, &complete);
						printf("Objetivo completo\n");
						complete = false;
					}
					if(game.level == 2)
					{
						levelTres = malloc(sizeof(LevelTres));
						game.level = 3;
						inputs[3] = true;
						createLevelTres(levelTres, player);
						initDrawGatesLevelTres(levelTres);
						drawLogicLevelTres(inputs[0], inputs[1], inputs[2], inputs[3], &complete, levelTres);
						printf("Objetivo completo\n");
						complete = false;
					}
					if(game.level == 1)
					{
						levelDois = malloc(sizeof(LevelDois));
						game.level = 2;
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						createLevelDois(levelDois, player);
						initDrawGatesLevelDois(levelDois);
						drawLogicLevelDois(inputs[0], inputs[1], inputs[2], levelDois, &complete);
						printf("Objetivo completo \n");
						complete = false;
					}
					if(game.level == 0)
					{
						levelOne = malloc(sizeof(LevelOne));
						game.level = 1;
						//fundo = SetBackGroundImage("./data/levels/fase1/teste.png");
						createLevelOne(levelOne, player);
						initDrawGatesLevelOne(levelOne);
						drawLogicLevelOne(inputs[0], inputs[1], inputs[2], levelOne, &complete);
						printf("Objetivo completo \n");
						complete = false;
					}
				}
			}
		}
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
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
				if (game.mute == 0)
				{
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
        //Exibe fundo
		al_draw_bitmap(fundo, 0, 0, 0);
		al_draw_textf(game.fonte_menu, al_map_rgb(0, 0, 0), 200, 570, ALLEGRO_ALIGN_CENTRE, get_idioma("Level: %d") , game.level);
		al_draw_textf(game.fonte_menu, al_map_rgb(0, 0, 0), 600, 570, ALLEGRO_ALIGN_CENTRE, get_idioma("Moves: %d") , player->chances);
		if(complete)
		{
			objectiveComplete();
		}
		else
		{
			showObjective(game.level);
		}
		if (game.level == 0)
		{
			drawLevelZero(levelZero);
		}
		if (game.level == 1)
		{
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
			drawLevelTres(levelTres);
			if(isDestroyed == false)
			{
				destroyLevelDois(levelDois);
				free(levelDois);
				isDestroyed = true;
			}
		}
		if (game.level == 4)
		{
			drawLevelQuatro(levelQuatro);
			if(isDestroyed == false)
			{
				destroyLevelTres(levelTres);
				free(levelTres);
				isDestroyed = true;
			}
		}
		if (game.level == 5)
		{
			drawLevelCinco(levelCinco);
			if(isDestroyed == false)
			{
				destroyLevelQuatro(levelQuatro);
				free(levelQuatro);
				isDestroyed = true;
			}
		}
		ValidaMovimento(player);
		al_draw_bitmap(soundIcon, 750, 20, 0);
		if(redraw && al_is_event_queue_empty(game.fila_eventos)) {
			redraw = false;
			al_flip_display();
		}
	}
	//destroyLevelTres(levelTres);
	//al_destroy_sample_instance(game.songInstance);
	//free(levelTres);
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

	if(level == 1 || level == 2 || level == 4){
		if (isColliding(165, 146, 55, 35, player)    ||
			isColliding(165, 238, 55, 35, player)   ||
			isColliding(165, 335, 55, 35, player))
		{
			return true;
		}
		else return false;
	}
	if(level == 3)
	{
		if (isColliding(163, 110, 55, 35, player)   ||
			isColliding(163, 206, 55, 35, player)   ||
			isColliding(163, 269, 55, 35, player)   ||
			isColliding(163, 368, 55, 35, player))
		{
			return true;
		}
		else return false;
	}
	if(level == 5)
	{
		if (isColliding(101, 112, 55, 90, player))
		{
			return true;
		}
		else return false;
	}
	return false;
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

void objectiveComplete(){
	al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 20, 20, 0, get_idioma("Complete"));
	al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 20, 40, 0, get_idioma("Continue"));
}

void showObjective(int level){
	al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 20, 20, 0, get_idioma("Objective"));
	switch(level)
	{
		case 0:
			al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 20, 40, 0, get_idioma("Level0"));
		break;
		case 5:
			al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 20, 40, 0, get_idioma("Decoder"));
			al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 20, 60, 0, get_idioma("Level5"));
		break;
		default:
			al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 20, 40, 0, get_idioma("DefaultObjective"));
		break;
	}
}