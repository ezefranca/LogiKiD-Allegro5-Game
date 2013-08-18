/*
 * Informações comuns entre os arquivos
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#define ALTURA  800
#define LARGURA 600

struct Game
{
	ALLEGRO_TIMER *timer;
	ALLEGRO_DISPLAY *janela;
	ALLEGRO_EVENT_QUEUE *fila_eventos;
};

struct Game game;

void GameLoop();
bool inicializar();
