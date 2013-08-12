/*
 * Contem as informações do sprite sheet
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

struct ImageSheet
{
	ALLEGRO_BITMAP *image;

	int x;
	int y;

	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
};
