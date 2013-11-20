<<<<<<< HEAD
=======
#ifndef FASE3_H
#define FASE3_H

>>>>>>> tales
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

<<<<<<< HEAD
=======
#include "../../Player.h"
>>>>>>> tales
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
	ALLEGRO_BITMAP *portas;
       char cChances[5];
	bool isOn[5];
	int chances;
} LevelTres;

<<<<<<< HEAD
//void logicLevelTres(bool gateOne, bool gateTwo, bool gateThree, Player *player);
void initDrawGatesLevelTres(LevelTres *LevelTres);
void drawLevelTres(LevelTres *LevelTres);
void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, LevelTres *LevelTres);
void destroyLevelTres(LevelTres *LevelTres);
=======
void logicLevelTres(bool *gateOne, bool *gateTwo, bool *gateThree, bool *gateFour, Player *player);
void initDrawGatesLevelTres(LevelTres *LevelTres);
void drawLevelTres(LevelTres *LevelTres);
void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, bool *complete, LevelTres *LevelTres);
void destroyLevelTres(LevelTres *LevelTres);

#endif
>>>>>>> tales
