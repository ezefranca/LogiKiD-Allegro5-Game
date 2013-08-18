/*
 * Logica principal
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include "comum.h"
#include "Player.h"

void GameLoop()
{
	bool sair = false;
	bool direita = false, esquerda = false;
	bool sobe = false, desce = false;
	bool idleE = false, idleD = true; // idle direita, idle esquerda

	int posInSprite = 0;

	struct Player player;
	player.Image.x = ALTURA / 2;
	player.Image.y = LARGURA / 2;
	player.Image.maxFrame = 6;
	player.Image.curFrame = 0;
	player.Image.frameCount = 0;
	player.Image.frameDelay = 4;
	player.Image.frameWidth = 104;
	player.Image.frameHeight = 147;
	player.Image.image = al_load_bitmap("./data/gb_walk.png");

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
			case ALLEGRO_KEY_UP:
				if(desce != true)
					sobe = true;
				break;
			case ALLEGRO_KEY_DOWN:
				if(sobe != true)
					desce = true;
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
				player.Image.curFrame = 0;
				player.Image.frameCount = 0;
			}
			if(esquerda == true)
			{
				idleE = true;
				idleD = false;
				esquerda = false;

				// reseta os valores dos sprites
				player.Image.curFrame = 0;
				player.Image.frameCount = 0;
			}
			if(sobe == true)
			{
				sobe = false;
				desce = false;
			}
			if(desce == true)
			{
				sobe = false;
				desce = false;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			if(direita == true)
				moveDireita(&player);
			if(esquerda == true)
				moveEsquerda(&player);
			if(sobe == true)
				moveCima(&player);
			if(desce == true)
				moveBaixo(&player);
		}
		/* teste fundo */
		al_draw_bitmap(fundo, 0, 0, 0);

		if(idleE == true)
			al_draw_bitmap_region(player.Image.image, player.Image.frameWidth, 303, player.Image.frameWidth, player.Image.frameHeight, player.Image.x, player.Image.y, 0);
		else if(idleD == true)
			al_draw_bitmap_region(player.Image.image, 0, 303, player.Image.frameWidth, player.Image.frameHeight, player.Image.x, player.Image.y, 0);
		else
			al_draw_bitmap_region(player.Image.image, player.Image.curFrame * player.Image.frameWidth, posInSprite, player.Image.frameWidth, player.Image.frameHeight, player.Image.x, player.Image.y, 0);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
}
