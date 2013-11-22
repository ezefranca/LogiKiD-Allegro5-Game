#include "../../comum.h"
#include "fase0.h"

void createLevelZero(LevelZero *levelZero)
{
	levelZero->circ1_on = al_load_bitmap("./data/levels/fase0/circ1_on.png");
	levelZero->circ1_off = al_load_bitmap("./data/levels/fase0/circ1_off.png");
}


void logicLevelZero(bool *gateOne, bool *complete, LevelZero *levelZero, Player *player){
	if ((player->state.x > 200 && player->state.x < 318) && (player->state.y > 185 && player->state.y < 275))
	{
		if(*gateOne == false)
		{
			*gateOne  = true;
		}
		else *gateOne = false;
		printf("Mudando porta 1\n");
	}
	if(*gateOne)
	{
		levelZero->circ1 = levelZero->circ1_on;
		*complete = true;
	}
	if(!*gateOne)
	{
		levelZero->circ1 = levelZero->circ1_off;
	}
}

void drawLevelZero(LevelZero *levelZero){
	al_draw_bitmap(levelZero->circ1, 0, 0 , 0);
}

void destroyLevelZero(LevelZero *levelZero){
	al_destroy_bitmap(levelZero->circ1_on);
	al_destroy_bitmap(levelZero->circ1_off);
	//al_destroy_bitmap(levelZero->circ1);
	//al_destroy_bitmap(levelZero->portas);
}