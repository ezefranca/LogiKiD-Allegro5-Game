<<<<<<< HEAD
=======
#ifndef LEVELZERO_H
#define LEVELZERO_H

>>>>>>> tales
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

<<<<<<< HEAD
=======
#include "../../Player.h"

>>>>>>> tales
typedef struct {
	ALLEGRO_BITMAP *circ1;
	ALLEGRO_BITMAP *portas;

	bool isOn[5];
} LevelZero;

<<<<<<< HEAD
void logicLevelZero(bool gateOne, LevelZero *levelZero);
void drawLevelZero(LevelZero *levelZero);
void destroyLevelZero(LevelZero *levelZero);
void initDrawGatesLevelZero(LevelZero *levelZero);
=======
void logicLevelZero(bool *gateOne, bool *complete, LevelZero *levelZero, Player *player);
void drawLevelZero(LevelZero *levelZero);
void destroyLevelZero(LevelZero *levelZero);
void initDrawGatesLevelZero(LevelZero *levelZero);

#endif
>>>>>>> tales
