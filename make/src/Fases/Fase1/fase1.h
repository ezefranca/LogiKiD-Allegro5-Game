#ifndef FASE1_H
#define FASE1_H

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
	ALLEGRO_BITMAP *portas;

	bool isOn[5];
} LevelOne;
//O que eu quero fazer é usar essa função aqui
void logicLevelOne(bool *gateOne, bool *gateTwo, bool *gateThree, Player *player);
void drawLogicLevelOne(bool gateOne, bool gateTwo, bool gateThree, LevelOne *levelOne, bool *complete);
void drawLevelOne(LevelOne *levelOne);
void destroyLevelOne(LevelOne *levelOne);
void initDrawGatesLevelOne(LevelOne *levelOne);

#endif