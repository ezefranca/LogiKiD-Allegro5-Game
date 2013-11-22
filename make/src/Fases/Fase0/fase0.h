#ifndef LEVELZERO_H
#define LEVELZERO_H

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "../../Player.h"

typedef struct {

	int chances;
	ALLEGRO_BITMAP *circ1;
	
	ALLEGRO_BITMAP *circ1_on;
	ALLEGRO_BITMAP *circ1_off;

	//ALLEGRO_BITMAP *portas;

	bool isOn[5];
} LevelZero;

void createLevelZero(LevelZero *levelZero);
void logicLevelZero(bool *gateOne, bool *complete, LevelZero *levelZero, Player *player);
void drawLevelZero(LevelZero *levelZero);
void destroyLevelZero(LevelZero *levelZero);
void initDrawGatesLevelZero(LevelZero *levelZero);

#endif