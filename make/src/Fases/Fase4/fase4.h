#ifndef FASE4_H
#define FASE4_H

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
	ALLEGRO_BITMAP *circ3_on;
	ALLEGRO_BITMAP *circ4_on;
	ALLEGRO_BITMAP *circ5_on;
	ALLEGRO_BITMAP *circ6_on;
	ALLEGRO_BITMAP *circ7_on;

	ALLEGRO_BITMAP *circ1_off;
	ALLEGRO_BITMAP *circ2_off;
	ALLEGRO_BITMAP *circ3_off;

	ALLEGRO_BITMAP *circ1;
	ALLEGRO_BITMAP *circ2;
	ALLEGRO_BITMAP *circ3;
	ALLEGRO_BITMAP *circ4;
	ALLEGRO_BITMAP *circ5;
	ALLEGRO_BITMAP *circ6;
	ALLEGRO_BITMAP *circ7;

	ALLEGRO_BITMAP *circ_base;
	ALLEGRO_BITMAP *portas;

	bool isOn[5];

} LevelQuatro;


void createLevelQuatro(LevelQuatro *levelQuatro);
void logicLevelQuatro(bool *gateOne, bool *gateTwo, bool *gateThree, Player *player);
void initDrawGatesLevelQuatro(LevelQuatro *LevelQuatro);
void drawLevelQuatro(LevelQuatro *LevelQuatro);
void drawLogicLevelQuatro(bool gateOne, bool gateTwo, bool gateThree, LevelQuatro *LevelQuatro, bool *complete);
void destroyLevelQuatro(LevelQuatro *LevelQuatro);

#endif