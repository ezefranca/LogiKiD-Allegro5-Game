#include "../../comum.h"
#include "fase4.h"
#include "../../Player.h"

void createLevelQuatro(LevelQuatro *levelQuatro){
	levelQuatro->circ1_on = al_load_bitmap("./data/levels/fase4/circ1_on.png");
	levelQuatro->circ2_on = al_load_bitmap("./data/levels/fase4/circ2_on.png");
	levelQuatro->circ3_on = al_load_bitmap("./data/levels/fase4/circ3_on.png");
	
	levelQuatro->circ1_off = al_load_bitmap("./data/levels/fase4/circ1_off.png");
	levelQuatro->circ2_off = al_load_bitmap("./data/levels/fase4/circ2_off.png");
	levelQuatro->circ3_off = al_load_bitmap("./data/levels/fase4/circ3_off.png");

	levelQuatro->circ4 = al_load_bitmap("./data/levels/fase4/circ4_on.png");
	levelQuatro->circ5 = al_load_bitmap("./data/levels/fase4/circ5_on.png");
	levelQuatro->circ6 = al_load_bitmap("./data/levels/fase4/circ6_on.png");
	levelQuatro->circ7 = al_load_bitmap("./data/levels/fase4/circ7_on.png");

	levelQuatro->circ_base = al_load_bitmap("./data/levels/fase4/circ_off.png");
	levelQuatro->portas = al_load_bitmap("./data/levels/fase4/portas.png");
}

void logicLevelQuatro(bool *gateOne, bool *gateTwo, bool *gateThree, Player *player)
{
	if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 65 && player->state.y < 154))
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
	if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 155 && player->state.y < 238))
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
	if((player->state.x > 105 && player->state.x < 230) && (player->state.y > 254 && player->state.y < 338))
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

void drawLogicLevelQuatro(bool gateOne, bool gateTwo, bool gateThree, LevelQuatro *levelQuatro, bool *complete){
	if(gateOne)
	{
		levelQuatro->circ1 = levelQuatro->circ1_on;
	}
	else
	{
		levelQuatro->circ1 = levelQuatro->circ1_off;
	}
	if(gateTwo)
	{
		levelQuatro->circ2 = levelQuatro->circ2_on;
	}
	else
	{
		levelQuatro->circ2 = levelQuatro->circ2_off;
	}
	if(gateThree)
	{
		levelQuatro->circ3 = levelQuatro->circ3_on;
	}
	else
	{
		levelQuatro->circ3 = levelQuatro->circ3_off;
	}
	if(!(!gateOne || gateTwo))
	{
		levelQuatro->isOn[0] = true;
	}
	else
	{
		levelQuatro->isOn[0] = false;
	}
	if(gateTwo && gateThree)
	{
		levelQuatro->isOn[1] = true;
	}
	else
	{
		levelQuatro->isOn[1] = false;
	}
	if(!(!gateOne || gateTwo) && gateTwo)
	{
		levelQuatro->isOn[2] = true;
	}
	else
	{
		levelQuatro->isOn[2] = false;
	}
	if(levelQuatro->isOn[0] && !levelQuatro->isOn[1] && !levelQuatro->isOn[2])
	{
		levelQuatro->isOn[3] = true;
		*complete = true;
	}
	else
	{
		levelQuatro->isOn[3] = false;
	}
}

void initDrawGatesLevelQuatro(LevelQuatro *LevelQuatro){
	int i;

	for(i = 0; i < 5; i++){
		LevelQuatro->isOn[i] = false;
	}
}

void drawLevelQuatro(LevelQuatro *LevelQuatro){
	al_draw_bitmap(LevelQuatro->circ_base, 0, 0, 0);
	al_draw_bitmap(LevelQuatro->circ1, 0, 0, 0);
	al_draw_bitmap(LevelQuatro->circ2, 0, 0, 0);
	al_draw_bitmap(LevelQuatro->circ3, 0, 0, 0);
	if(LevelQuatro->isOn[0])al_draw_bitmap(LevelQuatro->circ4, 0, 0, 0);
	if(LevelQuatro->isOn[1])al_draw_bitmap(LevelQuatro->circ5, 0, 0, 0);
	if(LevelQuatro->isOn[2])al_draw_bitmap(LevelQuatro->circ6, 0, 0, 0);
	if(LevelQuatro->isOn[3])al_draw_bitmap(LevelQuatro->circ7, 0, 0, 0);
	al_draw_bitmap(LevelQuatro->portas, 0, 0, 0);
}

void destroyLevelQuatro(LevelQuatro *LevelQuatro){
	al_destroy_bitmap(LevelQuatro->circ1_on);
	al_destroy_bitmap(LevelQuatro->circ2_on);
	al_destroy_bitmap(LevelQuatro->circ3_on);

	al_destroy_bitmap(LevelQuatro->circ1_off);
	al_destroy_bitmap(LevelQuatro->circ2_off);
	al_destroy_bitmap(LevelQuatro->circ3_off);

	al_destroy_bitmap(LevelQuatro->circ4);
	al_destroy_bitmap(LevelQuatro->circ5);
	al_destroy_bitmap(LevelQuatro->circ6);
	al_destroy_bitmap(LevelQuatro->circ7);	

	al_destroy_bitmap(LevelQuatro->portas);
	al_destroy_bitmap(LevelQuatro->circ_base);
}