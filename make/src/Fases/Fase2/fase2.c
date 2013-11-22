#include "../../comum.h"
#include "fase2.h"
#include "../../Player.h"

void createLevelDois(LevelDois *levelDois){
	levelDois->circ1_on = al_load_bitmap("./data/levels/fase2/circ1_on.png");
	levelDois->circ2_on = al_load_bitmap("./data/levels/fase2/circ2_on.png");
	levelDois->circ3_on = al_load_bitmap("./data/levels/fase2/circ3_on.png");
	levelDois->circ4_on = al_load_bitmap("./data/levels/fase2/circ4_on.png");
	levelDois->circ5_on = al_load_bitmap("./data/levels/fase2/circ5_on.png");

	levelDois->circ1_off = al_load_bitmap("./data/levels/fase2/circ1_off.png");
	levelDois->circ2_off = al_load_bitmap("./data/levels/fase2/circ2_off.png");
	levelDois->circ3_off = al_load_bitmap("./data/levels/fase2/circ3_off.png");
	
	levelDois->circ6 = al_load_bitmap("./data/levels/fase2/circ_off.png");
	levelDois->portas = al_load_bitmap("./data/levels/fase2/portas.png");
}

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
	if(gateOne)
	{
		levelDois->circ1 = levelDois->circ1_on; 
	}
	else
	{
		levelDois->circ1 = levelDois->circ1_off;
	}
	if(gateTwo)
	{
		levelDois->circ2 = levelDois->circ2_on;
	}
	else
	{
		levelDois->circ2 = levelDois->circ2_off;
	}
	if(gateThree)
	{
		levelDois->circ3 = levelDois->circ3_on;
	}
	else
<<<<<<< HEAD
	{
		levelDois->circ3 = al_load_bitmap("./data/levels/fase2/circ3_off.png");
=======
	{ 
		levelDois->circ3 = levelDois->circ3_off;
>>>>>>> tales
	}
	if(gateOne && gateTwo)
	{
		levelDois->circ4 = levelDois->circ4_on;
		levelDois->isOn[3] = true;
	}
	else
	{
		levelDois->isOn[3] = false;
	}
	if((gateOne && gateTwo) || gateThree)
	{
		levelDois->circ5 = levelDois->circ5_on;
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