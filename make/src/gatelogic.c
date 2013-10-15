#include "comum.h"
#include "gatelogic.h"

ALLEGRO_BITMAP *logicLevelOne(bool gateOne, bool gateTwo, ALLEGRO_BITMAP *bitmap){
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
}