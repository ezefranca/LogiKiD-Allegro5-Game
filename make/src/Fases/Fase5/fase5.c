#include "../../comum.h"
#include "fase5.h"
#include "../../Player.h"

void createLevelCinco(LevelCinco *levelCinco, Player *player){
	player->chances = 0;
	levelCinco->circ1_on = al_load_bitmap("./data/levels/fase5/circ1_on.png");
	levelCinco->circ2_on = al_load_bitmap("./data/levels/fase5/circ2_on.png");

	levelCinco->circ1_off = al_load_bitmap("./data/levels/fase5/circ1_off.png");
	levelCinco->circ2_off = al_load_bitmap("./data/levels/fase5/circ2_off.png");

	levelCinco->circ3 = al_load_bitmap("./data/levels/fase5/circ3_on.png");

	levelCinco->circ_base = al_load_bitmap("./data/levels/fase5/circ_base.png");
}

void logicLevelCinco(bool *gateOne, bool *gateTwo, Player *player)
{
	if((player->state.x > 40 && player->state.x < 160) && (player->state.y > 30 && player->state.y < 107))
	{
		player->chances++;
		if(*gateOne == false){
			*gateOne = true;
			printf("False para true\n");
		}
		else{
			*gateOne = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 40 && player->state.x < 160) && (player->state.y > 106 && player->state.y < 167))
	{
		player->chances++;
		if(*gateTwo == false){
			*gateTwo = true;
			printf("False para true\n");
		}
		else{
			*gateTwo = false;
			printf("True para false\n");
		}
	}
}

void drawLogicLevelCinco(bool gateOne, bool gateTwo, LevelCinco *levelCinco, bool *complete){
	bool x = false, y = false, w = false, z = false;
	if(gateOne)
	{
		levelCinco->circ1 = levelCinco->circ1_on;
	}
	else
	{
		levelCinco->circ1 = levelCinco->circ1_off;
	}
	if(gateTwo)
	{
		levelCinco->circ2 = levelCinco->circ2_on;
	}
	else
	{
		levelCinco->circ2 = levelCinco->circ2_off;
	}
	if(!gateOne && !gateTwo)
	{
		levelCinco->isOn[0] = true;
		x = true;
	}
	else
	{
		levelCinco->isOn[0] = false;
	}
	if(gateOne && !gateTwo)
	{
		levelCinco->isOn[1] = true;
		y = true;
	}
	else
	{
		levelCinco->isOn[1] = false;
	}
	if(!gateOne && gateTwo)
	{
		levelCinco->isOn[2] = true;
		w = true;
	}
	else
	{
		levelCinco->isOn[2] = false;
	}
	if(gateOne && gateTwo)
	{
		levelCinco->isOn[3] = true;
		z = true;
	}
	else
	{
		levelCinco->isOn[3] = false;
	}
	if(x == true && y == true && w == true && z ==true){
		*complete = true;
	}
}

void initDrawGatesLevelCinco(LevelCinco *levelCinco){
	int i;

	for(i = 0; i < 5; i++){
		levelCinco->isOn[i] = false;
	}
}

void drawLevelCinco(LevelCinco *levelCinco){
	al_draw_bitmap(levelCinco->circ_base, 0, 0, 0);
	al_draw_bitmap(levelCinco->circ1, 0, 0, 0);
	al_draw_bitmap(levelCinco->circ2, 0, 0, 0);
	if(levelCinco->isOn[0])al_draw_bitmap(levelCinco->circ3, 0, 0, 0);
	if(levelCinco->isOn[1])al_draw_bitmap(levelCinco->circ3, 0, 96, 0);
	if(levelCinco->isOn[2])al_draw_bitmap(levelCinco->circ3, 0, 192, 0);
	if(levelCinco->isOn[3])al_draw_bitmap(levelCinco->circ3, 0, 288, 0);
}

void destroyLevelCinco(LevelCinco *levelCinco){
	al_destroy_bitmap(levelCinco->circ1_on);
	al_destroy_bitmap(levelCinco->circ2_on);

	al_destroy_bitmap(levelCinco->circ1_off);
	al_destroy_bitmap(levelCinco->circ2_off);

	al_destroy_bitmap(levelCinco->circ3);

	al_destroy_bitmap(levelCinco->circ_base);
}