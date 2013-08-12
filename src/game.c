/*
 * Logica principal
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include "comum.h"
#include "SpriteSheet.h"

struct ImageSheet image;

void moveDireita()
{
	if(++image.frameCount >= image.frameDelay)
	{
		if(++image.curFrame >= image.maxFrame)
			image.curFrame = 0;

		image.frameCount = 0;
	}

	image.x -= 4; // usado para controlar o fundo

	/*if(image.x >= LARGURA + image.frameWidth)
		image.x = 0; */
}

void moveEsquerda()
{
	if(++image.frameCount >= image.frameDelay)
	{
		if(++image.curFrame >= image.maxFrame)
			image.curFrame = 0;

		image.frameCount = 0;
	}

	image.x += 4; // usado para controlar o fundo

	/*if(image.x <= image.frameWidth)
		image.x = LARGURA; */
}

void GameLoop()
{
	bool sair = false;
	bool direita = false, esquerda = false;
	bool idleE = false, idleD = true; // idle direita, idle esquerda

	int posInSprite = 0;

	image.x = ALTURA / 2;
	image.y = LARGURA / 2;
	image.maxFrame = 6;
	image.curFrame = 0;
	image.frameCount = 0;
	image.frameDelay = 4;
	image.frameWidth = 104;
	image.frameHeight = 147;
	image.image = al_load_bitmap("./data/gb_walk.png");

	ALLEGRO_BITMAP *fundo = al_load_bitmap("./data/levels/FASE-1.png");

	al_start_timer(game.timer);
	while(!sair)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(game.fila_eventos, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			sair = true;

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
			case ALLEGRO_KEY_LEFT:
				if(direita != true)
				{
					posInSprite = 150;
					esquerda = true;
					idleE = false;
					idleD = false;
				}
				break;
			case ALLEGRO_KEY_RIGHT:
				if(esquerda != true)
				{
					posInSprite = 0;
					direita = true;

					idleE = false;
					idleD = false;
				}
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if(direita == true)
			{
				idleD = true;
				idleE = false;
				direita = false;

				// reseta os valores dos sprites
				image.curFrame = 0;
				image.frameCount = 0;
			}
			if(esquerda == true)
			{
				idleE = true;
				idleD = false;
				esquerda = false;

				// reseta os valores dos sprites
				image.curFrame = 0;
				image.frameCount = 0;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			if(direita == true)
				moveDireita();
			if(esquerda == true)
				moveEsquerda();
		}
		/* teste fundo */
		al_draw_bitmap(fundo, image.x, 0, 0);

		if(idleE == true)
			al_draw_bitmap_region(image.image, image.frameWidth, 303, image.frameWidth, image.frameHeight, 350, LARGURA/2, 0);
		else if(idleD == true)
			al_draw_bitmap_region(image.image, 0, 303, image.frameWidth, image.frameHeight, 350, LARGURA/2, 0);
		else
			al_draw_bitmap_region(image.image, image.curFrame * image.frameWidth, posInSprite, image.frameWidth, image.frameHeight, 350, LARGURA/2, 0);



		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
}
