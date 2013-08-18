/*
 * Logica principal
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include "comum.h"
#include "Player.h"
#include "EventTest.h"

void TextInScreen(const char *text, int flags)
{
	al_draw_text(game.fonte, al_map_rgb(255, 0, 0), 10, 10, flags, text);
}

ALLEGRO_BITMAP *SetBackGroundImage(const char *bk_path)
{
	return al_load_bitmap(bk_path);
}

void GameLoop()
{
	bool sair = false;
	struct Player player;
	
	CreatePlayer(&player, ALTURA/2, LARGURA/2);

	ALLEGRO_BITMAP *fundo = SetBackGroundImage("./data/levels/FASE-1.png");

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
				ProcessaMovimentoEsquerda(&player);
				
				StartEventTest(ev); // o parametro passado para o novo evento é o proprio evento, para o consumo do buffer de eventos...				
				break;
			case ALLEGRO_KEY_RIGHT:
				ProcessaMovimentoDireita(&player);
				break;
			case ALLEGRO_KEY_UP:
				ProcessaMovimentoCima(&player);
				break;
			case ALLEGRO_KEY_DOWN:
				ProcessaMovimentoBaixo(&player);
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			ValidaMovimento_CK_UP(&player);
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			ValidaMovimento_TIMER(&player);
		}
		/* teste fundo */
		al_draw_bitmap(fundo, 0, 0, 0);
		
		TextInScreen("Portas:", 0);
		
		ValidaMovimento(&player);
		
		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
}