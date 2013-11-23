#include "../../comum.h"
#include "fase3.h"
#include "../../Player.h"

void createLevelTres(LevelTres *levelTres){
	levelTres->circ1_on = al_load_bitmap("./data/levels/fase3/circ1_on.png");
	levelTres->circ2_on = al_load_bitmap("./data/levels/fase3/circ2_on.png");
	levelTres->circ3_on = al_load_bitmap("./data/levels/fase3/circ3_on.png");
	levelTres->circ4_on = al_load_bitmap("./data/levels/fase3/circ4_on.png");
	
	levelTres->circ1_off = al_load_bitmap("./data/levels/fase3/circ1_off.png");
	levelTres->circ2_off = al_load_bitmap("./data/levels/fase3/circ2_off.png");
	levelTres->circ3_off = al_load_bitmap("./data/levels/fase3/circ3_off.png");
	levelTres->circ4_off = al_load_bitmap("./data/levels/fase3/circ4_off.png");

	levelTres->circ5 = al_load_bitmap("./data/levels/fase3/circ5_on.png");
	levelTres->circ6 = al_load_bitmap("./data/levels/fase3/circ6_on.png");

	levelTres->circ_off = al_load_bitmap("./data/levels/fase3/circ_off.png");
	levelTres->saida = al_load_bitmap("./data/levels/fase3/saida_on.png");
	levelTres->portas = al_load_bitmap("./data/levels/fase3/portas.png");
}

void logicLevelTres(bool *gateOne, bool *gateTwo, bool *gateThree, bool *gateFour, Player *player)
{
	if((player->state.x > 102 && player->state.x < 222) && (player->state.y > 28 && player->state.y < 110))
	{
		if(*gateOne == false)
		{
			*gateOne = true;
			printf("False para true\n");
		}
		else{
			*gateOne = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 102 && player->state.x < 222) && (player->state.y > 124 && player->state.y < 199))
	{
		if(*gateTwo == false)
		{
			*gateTwo = true;
			printf("False para true\n");
		}
		else{
			*gateTwo = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 102 && player->state.x < 222) && (player->state.y > 198 && player->state.y < 269))
	{
		if(*gateThree == false)
		{
			*gateThree = true;
			printf("False para true\n");
		}
		else{
			*gateThree = false;
			printf("True para false\n");
		}
	}
	if((player->state.x > 102 && player->state.x < 222) && (player->state.y > 285 && player->state.y < 369))
	{
		if(*gateFour == false)
		{
			*gateFour = true;
			printf("False para true\n");
		}
		else{
			*gateFour = false;
			printf("True para false\n");
		}
	}
}

void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, bool *complete, LevelTres *levelTres)
{
	if(gateOne)
	{
		levelTres->circ1 = levelTres->circ1_on;
	}
	else
	{
		levelTres->circ1 = levelTres->circ1_off;
	}
	if(gateTwo)
	{
		levelTres->circ2 = levelTres->circ2_on;
	}
	else
	{
		levelTres->circ2 = levelTres->circ2_off;
	}
	if(gateThree)
	{
		levelTres->circ3 = levelTres->circ3_on;
	}
	else
	{
		levelTres->circ3 = levelTres->circ3_off;
	}
	if(gateFour)
	{
		levelTres->circ4 = levelTres->circ4_on;
	}
	else
	{
		levelTres->circ4 = levelTres->circ4_off;
	}
	if (!gateOne && gateTwo)
	{
		//levelTres->circ5 = levelTres->circ5_on;
		levelTres->isOn[0] = true;
	}
	else
	{
		levelTres->isOn[0] = false;
	}
	if (!gateThree || !gateFour)
	{
		//levelTres->circ6 = levelTres->circ6_on;
		levelTres->isOn[1] = true;
	}
	else
	{
		levelTres->isOn[1] = false;
	}
	if ((!gateOne && gateTwo) && (!gateThree || !gateFour))
	{
		levelTres->isOn[2] = true;
		*complete = true;
	}
	else
	{
		levelTres->isOn[2] = false;
	}
}

void initDrawGatesLevelTres(LevelTres *LevelTres)
{
	int i = 0;
	for(i = 1; i < 5; i++){
		LevelTres->isOn[i] = false;
	}
}

void drawLevelTres(LevelTres *levelTres){
	al_draw_bitmap(levelTres->circ_off, 0, 0 , 0);
	al_draw_bitmap(levelTres->circ1, 0, 0 , 0);
	al_draw_bitmap(levelTres->circ2, 0, 0 , 0);
	al_draw_bitmap(levelTres->circ3, 0, 0 , 0);
	al_draw_bitmap(levelTres->circ4, 0, 0 , 0);
	if(levelTres->isOn[0])al_draw_bitmap(levelTres->circ5, 0, 0 , 0);
	if(levelTres->isOn[1])al_draw_bitmap(levelTres->circ6, 0, 0 , 0);
	if(levelTres->isOn[2])al_draw_bitmap(levelTres->saida, 0, 0 , 0);
	al_draw_bitmap(levelTres->portas, 0, 0 , 0);
}

void destroyLevelTres(LevelTres *levelTres)
{	
	al_destroy_bitmap(levelTres->circ1_on);
	al_destroy_bitmap(levelTres->circ2_on);
	al_destroy_bitmap(levelTres->circ3_on);
	al_destroy_bitmap(levelTres->circ4_on);

	al_destroy_bitmap(levelTres->circ1_off);
	al_destroy_bitmap(levelTres->circ2_off);
	al_destroy_bitmap(levelTres->circ3_off);
	al_destroy_bitmap(levelTres->circ4_off);

	al_destroy_bitmap(levelTres->circ5);
	al_destroy_bitmap(levelTres->circ6);

	al_destroy_bitmap(levelTres->circ_off);
	al_destroy_bitmap(levelTres->saida);
	al_destroy_bitmap(levelTres->portas);
}