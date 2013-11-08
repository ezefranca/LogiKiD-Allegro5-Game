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
	ALLEGRO_BITMAP *portas;

	bool isOn[5];
} LevelTres;

void logicLevelTres(bool gateOne, bool gateTwo, LevelTres *LevelTres);
void drawLevelTres(LevelTres *LevelTres);
void destroyLevelTres(LevelTres *LevelTres);
void initDrawGatesLevelTres(LevelTres *LevelTres);