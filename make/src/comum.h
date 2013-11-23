/*
 * Informações comuns entre os arquivos
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#ifndef COMUM_H
#define COMUM_H

//#include <stdbool>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
//#include <allegro5\allegro_audio.h>

#define ALTURA  800
#define LARGURA 600

struct Game
{
	int mute;
	int level;
	ALLEGRO_SAMPLE *som;
	ALLEGRO_FONT *fonte;
	ALLEGRO_FONT *fonte_menu;
	ALLEGRO_FONT *fonte_logo;
	ALLEGRO_TIMER *timer;
	ALLEGRO_DISPLAY *janela;
	ALLEGRO_EVENT_QUEUE *fila_eventos;
	ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *songInstance;
    ALLEGRO_FONT *fonteKeys;
};

struct Game game;

bool inicializar();

#endif
