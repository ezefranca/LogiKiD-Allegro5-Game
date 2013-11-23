#ifndef PONTUACAO_H
#define PONTUACAO_H

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

typedef struct
{

	ALLEGRO_BITMAP *imageExcelente;
	ALLEGRO_BITMAP *imageBom;
	ALLEGRO_BITMAP *imageRegular;
	ALLEGRO_SAMPLE *somExcelente;
	ALLEGRO_SAMPLE *somBom;
	ALLEGRO_SAMPLE *somRegular;

}Ranked;
void loopQualifica(ALLEGRO_EVENT *ev);
void criaQualificacao(Ranked *ranking);
int qualificaJogador (Player *player, int gameLevel, ALLEGRO_EVENT_TYPE *ev);


#endif