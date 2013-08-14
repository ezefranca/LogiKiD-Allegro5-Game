/*
 * Contem as informações do sprite sheet
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

struct Image
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


struct Player
{
	int points;
	int level;
	struct Image image;
};

void moveDireita(struct Player *player);
void moveEsquerda(struct Player *player);
void moveCima(struct Player *player);
void moveBaixo(struct Player *player);

