/*
 * Logica principal
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include "comum.h"
#include "Player.h"

void GameLoop()
{
	struct Player player;

	bool sair = false;
	bool direita = false, esquerda = false;
	bool idleE = false, idleD = true; // idle direita, idle esquerda

	int posInSprite = 0;

	player.image.x = ALTURA / 2;
	player.image.y = LARGURA / 2;
	player.image.maxFrame = 6;
	player.image.curFrame = 0;
	player.image.frameCount = 0;
	player.image.frameDelay = 4;
	player.image.frameWidth = 104;
	player.image.frameHeight = 147;
	player.image.image = al_load_bitmap("./data/gb_walk.png");

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
				player.image.curFrame = 0;
				player.image.frameCount = 0;
			}
			if(esquerda == true)
			{
				idleE = true;
				idleD = false;
				esquerda = false;

				// reseta os valores dos sprites
				player.image.curFrame = 0;
				player.image.frameCount = 0;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			if(direita == true)
				moveDireita(&player);
			if(esquerda == true)
				moveEsquerda(&player);
		}
		/* teste fundo */
		al_draw_bitmap(fundo, player.image.x-LARGURA, 0, 0);

		if(idleE == true)
			al_draw_bitmap_region(player.image.image, player.image.frameWidth, 303, player.image.frameWidth, player.image.frameHeight, 350, LARGURA/2, 0);
		else if(idleD == true)
			al_draw_bitmap_region(player.image.image, 0, 303, player.image.frameWidth, player.image.frameHeight, 350, LARGURA/2, 0);
		else
			al_draw_bitmap_region(player.image.image, player.image.curFrame * player.image.frameWidth, posInSprite, player.image.frameWidth, player.image.frameHeight, 350, LARGURA/2, 0);



		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
}
