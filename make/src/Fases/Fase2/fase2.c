#include "../../comum.h"
#include "fase2.h"
#include "../../Player.h"

void logicLevelDois(bool *gateOne, bool *gateTwo, bool *gateThree, Player *player)
{
	if((player->state.x > 73 && player->state.x < 198) && (player->state.y > 33 && player->state.y < 122))
	{
		if(*gateOne == false){
			*gateOne = true;
			printf("False para true\n");
		}
		else{
			*gateOne = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 73 && player->state.x < 198) && (player->state.y > 123 && player->state.y < 206))
	{
		if(*gateTwo == false){
			*gateTwo = true;
			printf("False para true\n");
		}
		else{
			*gateTwo = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 73 && player->state.x < 198) && (player->state.y > 222 && player->state.y < 306))
	{
		if(*gateThree == false){
			*gateThree = true;
			printf("False para true\n");
		}
		else{
			*gateThree = false;
			printf("True para false\n");
		}
	}
}

void drawLogicLevelDois(bool gateOne, bool gateTwo, bool gateThree, LevelDois *levelDois, bool *complete){
	levelDois->circ6 = al_load_bitmap("./data/levels/fase2/circ_off.png");
	levelDois->portas = al_load_bitmap("./data/levels/fase2/portas.png");
	if(gateOne)
	{
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/circ1_on.png");
	}
	else
	{
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/circ1_off.png");
	}
	if(gateTwo)
	{
		levelDois->circ2 = al_load_bitmap("./data/levels/fase2/circ2_on.png");
	}
	else
	{
		levelDois->circ2 = al_load_bitmap("./data/levels/fase2/circ2_off.png");
	}
	if(gateThree)
	{
		levelDois->circ3 = al_load_bitmap("./data/levels/fase2/circ3_on.png");
	}
	else
	{
		levelDois->circ3 = al_load_bitmap("./data/levels/fase2/circ3_off.png");
	}
	if(gateOne && gateTwo)
	{
		levelDois->circ4 = al_load_bitmap("./data/levels/fase2/circ4_on.png");
		levelDois->isOn[3] = true;
	}
	else
	{
		levelDois->isOn[3] = false;
	}
	if((gateOne && gateTwo) || gateThree)
	{
		levelDois->circ5 = al_load_bitmap("./data/levels/fase2/circ5_on.png");
		levelDois->isOn[4] = true;
		*complete = true;
	}
	else
	{
		levelDois->isOn[4] = false;
	}
}

void initDrawGatesLevelDois(LevelDois *LevelDois){
	int i;

	for(i = 0; i < 5; i++){
		LevelDois->isOn[i] = false;
	}
	LevelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_zero.png");
	LevelDois->circ2 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_um.png");
	LevelDois->circ3 = al_load_bitmap("./data/levels/fase2/OR_zero_um_zero.png");
	LevelDois->circ4 = al_load_bitmap("./data/levels/fase2/OR_um_zero_zero.png");
	LevelDois->circ5 = al_load_bitmap("./data/levels/fase2/OR_um_um_um.png");
}

void drawLevelDois(LevelDois *LevelDois){
	al_draw_bitmap(LevelDois->circ6, 0, 0 , 0);
	al_draw_bitmap(LevelDois->circ1, 0, 0 , 0);
	al_draw_bitmap(LevelDois->circ2, 0, 0 , 0);
	al_draw_bitmap(LevelDois->circ3, 0, 0 , 0);
	if(LevelDois->isOn[3])al_draw_bitmap(LevelDois->circ4, 0, 0 , 0);
	if(LevelDois->isOn[4])al_draw_bitmap(LevelDois->circ5, 0, 0 , 0);
	al_draw_bitmap(LevelDois->portas, 0, 0 , 0);
}

void destroyLevelDois(LevelDois *LevelDois){
	al_destroy_bitmap(LevelDois->circ1);
	al_destroy_bitmap(LevelDois->circ2);
	al_destroy_bitmap(LevelDois->circ3);
	al_destroy_bitmap(LevelDois->circ4);
	al_destroy_bitmap(LevelDois->circ5);
	al_destroy_bitmap(LevelDois->portas);
}