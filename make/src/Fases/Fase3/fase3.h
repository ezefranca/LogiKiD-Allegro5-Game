#ifndef FASE3_H
#define FASE3_H

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "../../Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

typedef struct {
	ALLEGRO_BITMAP *circ1;
	ALLEGRO_BITMAP *circ2;
	ALLEGRO_BITMAP *circ3;
	ALLEGRO_BITMAP *circ4;
	ALLEGRO_BITMAP *circ5;
	ALLEGRO_BITMAP *circ6;

	ALLEGRO_BITMAP *circ1_on;
	ALLEGRO_BITMAP *circ2_on;
	ALLEGRO_BITMAP *circ3_on;
	ALLEGRO_BITMAP *circ4_on;
	ALLEGRO_BITMAP *circ5_on;
	ALLEGRO_BITMAP *circ6_on;
	
	ALLEGRO_BITMAP *circ1_off;
	ALLEGRO_BITMAP *circ2_off;
	ALLEGRO_BITMAP *circ3_off;
	ALLEGRO_BITMAP *circ4_off;

	ALLEGRO_BITMAP *circ_off;

	ALLEGRO_BITMAP *saida;
	ALLEGRO_BITMAP *portas;

    char cChances[5];
	bool isOn[5];
	int chances;
} LevelTres;

void createLevelTres(LevelTres *levelTres);
void logicLevelTres(bool *gateOne, bool *gateTwo, bool *gateThree, bool *gateFour, Player *player);
void initDrawGatesLevelTres(LevelTres *LevelTres);
void drawLevelTres(LevelTres *LevelTres);
void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, bool *complete, LevelTres *LevelTres);
void destroyLevelTres(LevelTres *LevelTres);

#endif