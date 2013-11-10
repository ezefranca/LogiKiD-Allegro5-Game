#include "../../comum.h"
#include "fase0.h"

void logicLevelZero(bool gateOne, bool gateTwo, LevelZero *levelZero){
	if(gateOne && !gateTwo)
	{
		levelZero->circ1 = al_load_bitmap("./data/levels/fase0/bus_um_zero.png");
	}
	else if(gateTwo && !gateOne)
	{
		levelZero->circ1 = al_load_bitmap("./data/levels/fase0/bus_zero_um.png");
	}
	else if (!gateOne && !gateTwo)
	{
		levelZero->circ1 = al_load_bitmap("./data/levels/fase0/bus_zero_zero.png");
	}
	else if(gateOne && gateTwo)
	{
		levelZero->circ1 = al_load_bitmap("./data/levels/fase0/bus_um_um.png");
	}
}


void initDrawGatesLevelZero(LevelZero *levelZero){
	int i;
	for(i = 0; i < 5; i++){
		levelZero->isOn[i] = false;
	}
	levelZero->circ1 = al_load_bitmap("./data/levels/fase0/bus_zero_zero.png");
}


void drawLevelZero(LevelZero *levelZero){
	al_draw_bitmap(levelZero->circ1, 0, 0 , 0);
	//al_draw_bitmap(levelZero->circ2, 0, 0 , 0);
	//if(levelZero->isOn[3])al_draw_bitmap(levelZero->circ4, 0, 0 , 0);
	//if(levelZero->isOn[4])al_draw_bitmap(levelZero->circ5, 0, 0 , 0);
}

void destroyLevelZero(LevelZero *levelZero){
	al_destroy_bitmap(levelZero->circ1);
	al_destroy_bitmap(levelZero->portas);
}