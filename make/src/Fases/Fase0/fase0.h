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
	ALLEGRO_BITMAP *circ1;
	ALLEGRO_BITMAP *portas;

	bool isOn[5];
} LevelZero;

void logicLevelZero(bool *gateOne, bool *complete, LevelZero *levelZero, Player *player);
void drawLevelZero(LevelZero *levelZero);
void destroyLevelZero(LevelZero *levelZero);
void initDrawGatesLevelZero(LevelZero *levelZero);

#endif