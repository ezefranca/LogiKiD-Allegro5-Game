#include "../../comum.h"
#include "fase1.h"

/*ALLEGRO_BITMAP *logicLevelOne(bool gateOne, bool gateTwo, ALLEGRO_BITMAP *bitmap){
	if(!gateOne && !gateTwo){
		return al_load_bitmap("./data/levels/fase1/teste_circuito_1.png");
	}
	if(gateOne && !gateTwo){
		return al_load_bitmap("./data/levels/fase1/teste_circuito2.png");
	}
	if(!gateOne && gateTwo){
		return al_load_bitmap("./data/levels/fase1/teste_circuito3.png");
	}
	if(gateOne && gateTwo){
		return al_load_bitmap("./data/levels/fase1/teste_circuito4.png");
	}
}*/

/*void loadLevelOne(LevelOne *levelOne){
	levelOne->circ1 = al_load_bitmap("./data/levels/fase1/circ1_off");
	levelOne->circ2 = al_load_bitmap("./data/levels/fase1/circ2_off");
	levelOne->circ3 = al_load_bitmap("./data/levels/fase1/circ3_off");
	levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_off");
	levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ1_off");
	levelOne->portas = al_load_bitmap("./data/levels/fase1/circ1_off");
}*/

void logicLevelOne(bool gateOne, bool gateTwo, bool gateThree, LevelOne *levelOne){
	if(gateOne)
	{
		levelOne->circ1 = al_load_bitmap("./data/levels/fase1/circ1_on.png");
	}
	else levelOne->circ1 = al_load_bitmap("./data/levels/fase1/circ1_off.png");
	if(gateTwo)
	{
		levelOne->circ2 = al_load_bitmap("./data/levels/fase1/circ2_on.png");
	}
	else levelOne->circ2 = al_load_bitmap("./data/levels/fase1/circ2_off.png");
	if(gateThree)
	{
		levelOne->circ3 = al_load_bitmap("./data/levels/fase1/circ3_on.png");
	}
	else levelOne->circ3 = al_load_bitmap("./data/levels/fase1/circ3_off.png");
	if(gateOne && gateTwo)
	{
		levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_on.png");
	}
	else levelOne->circ4 = al_load_bitmap("./data/levels/fase1/circ4_off.png");
	if(gateTwo || gateThree)
	{
		levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ5_on.png");
	}
	else levelOne->circ5 = al_load_bitmap("./data/levels/fase1/circ5_off.png");
	levelOne->portas = al_load_bitmap("./data/levels/fase1/portas.png");
}

void drawLevelOne(LevelOne *levelOne){
	al_draw_bitmap(levelOne->circ1, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ2, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ3, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ4, 0, 0 , 0);
	al_draw_bitmap(levelOne->circ5, 0, 0 , 0);
	al_draw_bitmap(levelOne->portas, 0, 0 , 0);
}