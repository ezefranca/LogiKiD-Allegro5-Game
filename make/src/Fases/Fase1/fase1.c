#include "../../comum.h"
#include "fase1.h"

void logicLevelOne(bool gateOne, bool gateTwo, bool gateThree, LevelOne *levelOne){
	if(gateOne)
	{
		levelOne->circ1 = al_load_bitmap("./data/levels/fase1/circ1_on.png");
		levelOne->isOn[0] = true;
	}
	else
	{
		//al_destroy_bitmap(levelOne->circ1);
		levelOne->isOn[0] = false;
	}
	if(gateTwo)
	{
		levelOne->circ2 = al_load_bitmap("./data/levels/fase1/circ2_on.png");
		levelOne->isOn[1] = true;
	}
	else
	{
		//al_destroy_bitmap(levelOne->circ2);
		levelOne->isOn[1] = false;
	}
	if(gateThree)
	{
		levelOne->circ3 = al_load_bitmap("./data/levels/fase1/circ3_on.png");
		levelOne->isOn[2] = true;	
	}
	else
	{ 
		//al_destroy_bitmap(levelOne->circ3);
		levelOne->isOn[2] = false;
	}
	if(gateOne && gateTwo)
	{
		levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_on.png");
		levelOne->isOn[3] = true;
	}
	else
	{
		//al_destroy_bitmap(levelOne->circ4);
		levelOne->isOn[3] = false;
	}
	if(gateTwo || gateThree)
	{
		levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ5_on.png");
		levelOne->isOn[4] = true;
	}
	else
	{
		//al_destroy_bitmap(levelOne->circ5);
		levelOne->isOn[4] = false;
	}
}

void initDrawGatesLevelOne(LevelOne *levelOne){
	int i;
	for(i = 0; i < 5; i++){
		levelOne->isOn[i] = false;
	}
	levelOne->circ1 = al_load_bitmap("./data/levels/fase1/circ1_on.png");
	levelOne->circ2 = al_load_bitmap("./data/levels/fase1/circ2_on.png");
	levelOne->circ3 = al_load_bitmap("./data/levels/fase1/circ3_on.png");
	levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_on.png");
	levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ5_on.png");
}

void drawLevelOne(LevelOne *levelOne){
	if(levelOne->isOn[0])al_draw_bitmap(levelOne->circ1, 0, 0 , 0);
	if(levelOne->isOn[1])al_draw_bitmap(levelOne->circ2, 0, 0 , 0);
	if(levelOne->isOn[2])al_draw_bitmap(levelOne->circ3, 0, 0 , 0);
	if(levelOne->isOn[3])al_draw_bitmap(levelOne->circ4, 0, 0 , 0);
	if(levelOne->isOn[4])al_draw_bitmap(levelOne->circ5, 0, 0 , 0);
}

void destroyLevelOne(LevelOne *levelOne){
	al_destroy_bitmap(levelOne->circ1);
	al_destroy_bitmap(levelOne->circ2);
	al_destroy_bitmap(levelOne->circ3);
	al_destroy_bitmap(levelOne->circ4);
	al_destroy_bitmap(levelOne->circ5);
	al_destroy_bitmap(levelOne->portas);
}