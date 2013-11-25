#ifndef SELECAOMENU_H
#define SELECAOMENU_H

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Player.h"

typedef struct
{
	int itmSelX, itmSelY;
	int currGate;

	ALLEGRO_BITMAP *ImagemMenu;
	ALLEGRO_BITMAP *PER1;
	ALLEGRO_BITMAP *PER2;
	ALLEGRO_BITMAP *PER3;
	ALLEGRO_BITMAP *PER4;
	ALLEGRO_BITMAP *PER5;
	ALLEGRO_BITMAP *PER6;
	ALLEGRO_BITMAP *PER7;
	ALLEGRO_BITMAP *Seletor;
	ALLEGRO_BITMAP *Seletor2;

	ALLEGRO_SAMPLE *menuSoundOpen;
}lgImages;

typedef enum { PERS1, PERS2, PERS3, PERS4, PERS5, PERS6, PERS7 } Personagem;
void menuSelecaox();
Personagem MenuLoadPerson(ALLEGRO_EVENT *ev, Player *player);

#endif