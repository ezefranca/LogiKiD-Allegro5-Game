#include "../../comum.h"
#include "fase3.h"
#include "../../Player.h"

void logicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, Player *player){
	if ((player->state.y > 40 && player->state.y < 60) && (player->state.x > 0 && player->state.x < 20))
	{
		gateOne = !gateOne;
		printf("Alavanca 1 %d \n", gateOne);
	}
	if ((player->state.y > 100 && player->state.y < 120) && (player->state.x > 0 && player->state.x < 20))
	{
		gateTwo = !gateTwo;
		printf("Alavanca 2 %d \n", gateTwo);
	}
	if ((player->state.y > 200 && player->state.y < 220) && (player->state.x > 0 && player->state.x < 20))
	{
		gateThree = !gateThree;
		printf("Alavanca 3 %d \n", gateFour);
	}
	if ((player->state.y > 260 && player->state.y < 280) && (player->state.x > 0 && player->state.x < 20))
	{
		gateFour = !gateFour;
		printf("Alavanca 4 %d \n", gateFour);
	}

}

void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, LevelTres *levelTres){
	al_draw_bitmap(levelTres->portas, 0, 0 , 0);
	if(gateOne)  levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-11XX.png");
	if(gateOne)  levelTres->circ2 = al_load_bitmap("./data/levels/fase3/DES1-XX11.png");
	//if(gateOne) levelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-1000.png");
	//if(gateOne) levelTres->circ4 = al_load_bitmap("./data/levels/fase3/DES1-1000.png");
	else levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-01XX.png");

}


void initDrawGatesLevelTres(LevelTres *LevelTres){
	int i = 0;
	LevelTres->isOn[i] = true;
	for(i = 1; i < 5; i++){
		LevelTres->isOn[i] = false;
	}
	LevelTres->portas = al_load_bitmap("./data/levels/fase3/DES1-0100.png");
	LevelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-1000.png");
	LevelTres->circ2 = al_load_bitmap("./data/levels/fase3/DES1-XX11.png");
	printf("iniciou\n");
}

void drawLevelTres(LevelTres *LevelTres){
	if(LevelTres->isOn[2] && !LevelTres->isOn[1] && !LevelTres->isOn[2] && !LevelTres->isOn[3])
		al_draw_bitmap(LevelTres->portas, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ1, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ2, 0, 0 , 0);
}

void destroyLevelTres(LevelTres *LevelTres){
	al_destroy_bitmap(LevelTres->circ1);
	al_destroy_bitmap(LevelTres->circ2);
	al_destroy_bitmap(LevelTres->circ3);
	al_destroy_bitmap(LevelTres->circ4);
	al_destroy_bitmap(LevelTres->circ5);
	al_destroy_bitmap(LevelTres->portas);
}