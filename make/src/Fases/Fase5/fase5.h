#ifndef FASE5_H
#define FASE5_H

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
	ALLEGRO_BITMAP *circ1_on;
	ALLEGRO_BITMAP *circ2_on;

	ALLEGRO_BITMAP *circ1_off;
	ALLEGRO_BITMAP *circ2_off;

	ALLEGRO_BITMAP *circ1;
	ALLEGRO_BITMAP *circ2;
	ALLEGRO_BITMAP *circ3;

	ALLEGRO_BITMAP *circ_base;

	bool isOn[5];

} LevelCinco;


void createLevelCinco(LevelCinco *levelCinco, Player *player);
void logicLevelCinco(bool *gateOne, bool *gateTwo, Player *player);
void initDrawGatesLevelCinco(LevelCinco *LevelCinco);
void drawLevelCinco(LevelCinco *LevelCinco);
void drawLogicLevelCinco(bool gateOne, bool gateTwo, LevelCinco *levelCinco, bool *complete);
void destroyLevelCinco(LevelCinco *LevelCinco);

#endif