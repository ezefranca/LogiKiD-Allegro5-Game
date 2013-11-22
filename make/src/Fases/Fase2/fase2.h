#ifndef FASE2_H
#define FASE2_H

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

	ALLEGRO_BITMAP *circ1_off;
	ALLEGRO_BITMAP *circ2_off;
	ALLEGRO_BITMAP *circ3_off;
	
	ALLEGRO_BITMAP *circ1;
	ALLEGRO_BITMAP *circ2;
	ALLEGRO_BITMAP *circ3;
	ALLEGRO_BITMAP *circ4;
	ALLEGRO_BITMAP *circ5;

	ALLEGRO_BITMAP *circ6;
	ALLEGRO_BITMAP *portas;

	bool isOn[5];

} LevelDois;

<<<<<<< HEAD

=======
void createLevelDois(LevelDois *levelDois);
>>>>>>> tales
void logicLevelDois(bool *gateOne, bool *gateTwo, bool *gateThree, Player *player);
void initDrawGatesLevelDois(LevelDois *LevelDois);
void drawLevelDois(LevelDois *LevelDois);
void drawLogicLevelDois(bool gateOne, bool gateTwo, bool gateThree, LevelDois *LevelDois, bool *complete);
void destroyLevelDois(LevelDois *LevelDois);

#endif

