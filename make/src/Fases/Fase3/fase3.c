#include "../../comum.h"
#include "fase3.h"
#include "../../Player.h"

void logicLevelTres(bool gateOne, bool gateTwo, bool gateThree, Player *player){
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

void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, LevelTres *levelTres){
	levelTres->circ6 = al_load_bitmap("./data/levels/fase2/circ_off.png");
	levelTres->portas = al_load_bitmap("./data/levels/fase2/portas.png");
	if(gateOne)
	{
		levelTres->circ1 = al_load_bitmap("./data/levels/fase2/circ1_on.png");
	}
	else
	{
		levelTres->circ1 = al_load_bitmap("./data/levels/fase2/circ1_off.png");
	}
	if(gateTwo)
	{
		levelTres->circ2 = al_load_bitmap("./data/levels/fase2/circ2_on.png");
	}
	else
	{
		levelTres->circ2 = al_load_bitmap("./data/levels/fase2/circ2_off.png");
	}
	if(gateThree)
	{
		levelTres->circ3 = al_load_bitmap("./data/levels/fase2/circ3_on.png");
	}
	else
	{
		levelTres->circ3 = al_load_bitmap("./data/levels/fase2/circ3_off.png");
	}
	if(gateOne && gateTwo)
	{
		levelTres->circ4 = al_load_bitmap("./data/levels/fase2/circ4_on.png");
		levelTres->isOn[3] = true;
	}
	else
	{
		levelTres->isOn[3] = false;
	}
	if((gateOne && gateTwo) || gateThree)
	{
		levelTres->circ5 = al_load_bitmap("./data/levels/fase2/circ5_on.png");
		levelTres->isOn[4] = true;
	}
	else
	{
		levelTres->isOn[4] = false;
	}
}

void initDrawGatesLevelTres(LevelTres *LevelTres){
	int i;

	for(i = 0; i < 5; i++){
		LevelTres->isOn[i] = false;
	}
	LevelTres->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_zero.png");
	LevelTres->circ2 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_um.png");
	LevelTres->circ3 = al_load_bitmap("./data/levels/fase2/OR_zero_um_zero.png");
	LevelTres->circ4 = al_load_bitmap("./data/levels/fase2/OR_um_zero_zero.png");
	LevelTres->circ5 = al_load_bitmap("./data/levels/fase2/OR_um_um_um.png");
}

void drawLevelTres(LevelTres *LevelTres){
	al_draw_bitmap(LevelTres->circ6, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ1, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ2, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ3, 0, 0 , 0);
	if(LevelTres->isOn[3])al_draw_bitmap(LevelTres->circ4, 0, 0 , 0);
	if(LevelTres->isOn[4])al_draw_bitmap(LevelTres->circ5, 0, 0 , 0);
	al_draw_bitmap(LevelTres->portas, 0, 0 , 0);
}

void destroyLevelTres(LevelTres *LevelTres){
	al_destroy_bitmap(LevelTres->circ1);
	al_destroy_bitmap(LevelTres->circ2);
	al_destroy_bitmap(LevelTres->circ3);
	al_destroy_bitmap(LevelTres->circ4);
	al_destroy_bitmap(LevelTres->circ5);
	al_destroy_bitmap(LevelTres->portas);
}