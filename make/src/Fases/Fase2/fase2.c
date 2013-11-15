#include "../../comum.h"
#include "fase2.h"
#include "../../Player.h"

void logicLevelDois(bool gateOne, bool gateTwo, bool gateThree, LevelDois *levelDois){
	if(!gateOne && !gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_zero.png");
	if(gateOne && !gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_zero_zero.png");
	if(!gateOne && gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_um_zero.png");
	if(gateOne && gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_um_zero.png");
	if(!gateOne && !gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_um.png");
	if(gateOne && !gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_zero_um.png");
	if(!gateOne && gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_um_um.png");
	if(gateOne && gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_um_um.png");
}

void drawLogicLevelDois(bool gateOne, bool gateTwo, bool gateThree, LevelDois *levelDois){
	if(!gateOne && !gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_zero.png");
	if(gateOne && !gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_zero_zero.png");
	if(!gateOne && gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_um_zero.png");
	if(gateOne && gateTwo && !gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_um_zero.png");
	if(!gateOne && !gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_zero_um.png");
	if(gateOne && !gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_zero_um.png");
	if(!gateOne && gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_zero_um_um.png");
	if(gateOne && gateTwo && gateThree)
		levelDois->circ1 = al_load_bitmap("./data/levels/fase2/OR_um_um_um.png");
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
	//al_draw_bitmap(LevelDois->portas, 0, 0 , 0);
	al_draw_bitmap(LevelDois->circ1, 0, 0 , 0);
	al_draw_bitmap(LevelDois->circ2, 0, 0 , 0);
	al_draw_bitmap(LevelDois->circ3, 0, 0 , 0);
	if(LevelDois->isOn[3])al_draw_bitmap(LevelDois->circ4, 0, 0 , 0);
	if(LevelDois->isOn[4])al_draw_bitmap(LevelDois->circ5, 0, 0 , 0);
}

void destroyLevelDois(LevelDois *LevelDois){
	al_destroy_bitmap(LevelDois->circ1);
	al_destroy_bitmap(LevelDois->circ2);
	al_destroy_bitmap(LevelDois->circ3);
	al_destroy_bitmap(LevelDois->circ4);
	al_destroy_bitmap(LevelDois->circ5);
	al_destroy_bitmap(LevelDois->portas);
}