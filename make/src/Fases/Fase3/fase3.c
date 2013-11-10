#include "../../comum.h"
#include "fase3.h"

void logicLevelTres(bool gateOne, bool gateTwo, LevelTres *levelTres){
	if(gateOne && !gateTwo)
	{
		levelTres->circ1 = al_load_bitmap("./data/levels/fase3/AND_zero_zero.png");
	}
	else if(gateTwo && !gateOne)
	{
		levelTres->circ1 = al_load_bitmap("./data/levels/fase3/AND_zero_um.png");
	}
	else if (!gateOne && !gateTwo)
	{
		levelTres->circ1 = al_load_bitmap("./data/levels/fase3/AND_um_zero.png");
	}
	else if(gateOne && gateTwo)
	{
		levelTres->circ1 = al_load_bitmap("./data/levels/fase3/AND_um_um.png");
	}
}


void initDrawGatesLevelTres(LevelTres *levelTres){
	int i;
	for(i = 0; i < 5; i++){
		levelTres->isOn[i] = false;
	}
	levelTres->circ1 = al_load_bitmap("./data/levels/fase0/teste.png");
}


void drawLevelTres(LevelTres *levelTres){
	al_draw_bitmap(levelTres->circ1, 0, 0 , 0);
	//al_draw_bitmap(levelTres->circ2, 0, 0 , 0);
	//if(levelTres->isOn[3])al_draw_bitmap(levelTres->circ4, 0, 0 , 0);
	//if(levelTres->isOn[4])al_draw_bitmap(levelTres->circ5, 0, 0 , 0);
}

void destroyLevelTres(LevelTres *levelTres){
	al_destroy_bitmap(levelTres->circ1);
	al_destroy_bitmap(levelTres->portas);
}