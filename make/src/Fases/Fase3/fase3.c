#include "../../comum.h"
#include "fase3.h"
#include "../../Player.h"

void logicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, Player *player){
	if ((player->state.y > 40 && player->state.y < 70) && (player->state.x > 0 && player->state.x < 20))
	{
		gateOne = !gateOne;
		printf("Alavanca 1 %d \n", gateOne);
	}

}

void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, LevelTres *levelTres){
	if(gateOne) levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-1000.png");
	else levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-01XX.png");
}

void initDrawGatesLevelTres(LevelTres *LevelTres){
	int i;

	for(i = 0; i < 5; i++){
		LevelTres->isOn[i] = false;
	}
	LevelTres->portas = al_load_bitmap("./data/levels/fase3/DES1-0100.png");
	LevelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-1000.png");
	printf("iniciou\n");
}

void drawLevelTres(LevelTres *LevelTres){

	al_draw_bitmap(LevelTres->portas, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ1, 0, 0 , 0);
}

void destroyLevelTres(LevelTres *LevelTres){
	al_destroy_bitmap(LevelTres->circ1);
	al_destroy_bitmap(LevelTres->circ2);
	al_destroy_bitmap(LevelTres->circ3);
	al_destroy_bitmap(LevelTres->circ4);
	al_destroy_bitmap(LevelTres->circ5);
	al_destroy_bitmap(LevelTres->portas);
}