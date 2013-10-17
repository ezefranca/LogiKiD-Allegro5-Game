#include "../../comum.h"
#include "fase1.h"
#include "../../Player.h"

void logicLevelOne(bool gateOne, bool gateTwo, bool gateThree, Player *player){
	if ((player->state.y > 54 && player->state.y < 122) &&
		(player->state.x > 40 && player->state.x < 46))
	{
		if(gateOne == false)
		{
			gateOne = true;
		}
		else gateOne = false;
		printf("Mudando porta 1\n");
	}
	if((player->state.y > 150 && player->state.y < 218) &&
		(player->state.x > 40 && player->state.x < 46))
	{
		if(gateTwo == false){
			gateTwo = true;
		}
		else gateTwo = false;
		printf("Mudando porta 2\n");
	}
	if((player->state.y > 246 && player->state.y < 310) &&
		(player->state.x > 40 && player->state.x < 46))
	{
		if(gateThree == false){
			gateThree = true;
		}
		else gateThree = false;
		printf("Mudando porta 3\n");
	}
}

void drawLogicLevelOne(bool gateOne, bool gateTwo, bool gateThree, LevelOne *levelOne){
	if(gateOne)
	{
		levelOne->circ1 = al_load_bitmap("./data/levels/fase1/circ1_on.png");
	}
	else
	{
		levelOne->circ1 = al_load_bitmap("./data/levels/fase1/circ1_off.png");
	}
	if(gateTwo)
	{
		levelOne->circ2 = al_load_bitmap("./data/levels/fase1/circ2_on.png");
	}
	else
	{
		levelOne->circ2 = al_load_bitmap("./data/levels/fase1/circ2_off.png");
	}
	if(gateThree)
	{
		levelOne->circ3 = al_load_bitmap("./data/levels/fase1/circ3_on.png");
	}
	else
	{ 
		levelOne->circ3 = al_load_bitmap("./data/levels/fase1/circ3_off.png");
	}
	if(gateOne && gateTwo)
	{
		levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_on.png");
		levelOne->isOn[3] = true;
	}
	else
	{
		levelOne->isOn[3] = false;
	}
	if(gateTwo || gateThree)
	{
		levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ5_on.png");
		levelOne->isOn[4] = true;
	}
	else
	{
		levelOne->isOn[4] = false;
	}
}

void initDrawGatesLevelOne(LevelOne *levelOne){
	int i;
	for(i = 0; i < 5; i++){
		levelOne->isOn[i] = false;
	}
	levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_on.png");
	levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ5_on.png");
}

void drawLevelOne(LevelOne *levelOne){
	al_draw_bitmap(levelOne->circ1, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ2, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ3, 0, 0 , 0);
	if(levelOne->isOn[3])al_draw_bitmap(levelOne->circ4, 0, 0 , 0);
	if(levelOne->isOn[4])al_draw_bitmap(levelOne->circ5, 0, 0 , 0);
}

void destroyLevelOne(LevelOne *levelOne){
	al_destroy_bitmap(levelOne->circ1);
	al_destroy_bitmap(levelOne->circ2);
	al_destroy_bitmap(levelOne->circ3);
	al_destroy_bitmap(levelOne->circ4);
	al_destroy_bitmap(levelOne->circ5);
	al_destroy_bitmap(levelOne->portas);
}