#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

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

void logicLevelOne(bool gateOne, bool gateTwo, bool gateThree, LevelOne *levelOne);
void drawLevelOne(LevelOne *levelOne);
void destroyLevelOne(LevelOne *levelOne);
void initDrawGatesLevelOne(LevelOne *levelOne);