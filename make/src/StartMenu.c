#include "StartMenu.h"
#include "comum.h"
#include "config.h"
#include "gameloop.h"
#include "selecaomenu.h"
#include "../src/Menus/Opcoes.h"

/*
Imprime o menu inicial
*/
void PrintMenu(int MenuPosition)
{
	ALLEGRO_BITMAP *menu_fundo = al_load_bitmap("./data/levels/menu/BG4.png");
	al_draw_bitmap(menu_fundo, 0, 0, 0);
	//al_draw_scaled_bitmap(fundo, 0, 0, 640, 480, 0, 0, 800, 600, 0);
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 302, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	al_draw_text(game.fonte, al_map_rgb(0, 255, 0), 800 / 2, 305, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	al_draw_text(game.fonte_logo, al_map_rgb(0, 0, 0), 800 / 2, 330, ALLEGRO_ALIGN_CENTRE, get_idioma("LogiKid"));
	al_draw_text(game.fonte_logo, al_map_rgb(0, 255, 0), 800 / 2, 336, ALLEGRO_ALIGN_CENTRE, get_idioma("LogiKid"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, get_idioma("Start game"));
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 52, ALLEGRO_ALIGN_CENTRE, get_idioma("Start game"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 150, ALLEGRO_ALIGN_CENTRE, get_idioma("Options"));
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 152, ALLEGRO_ALIGN_CENTRE, get_idioma("Options"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 250, ALLEGRO_ALIGN_CENTRE, get_idioma("Exit"));
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 252, ALLEGRO_ALIGN_CENTRE, get_idioma("Exit"));

	switch(MenuPosition)
	{
		case 0:
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, get_idioma("--Start game--"));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 52, ALLEGRO_ALIGN_CENTRE, get_idioma("--Start game--"));
		break;
		case 1:
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 150, ALLEGRO_ALIGN_CENTRE, get_idioma("--Options--"));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 152, ALLEGRO_ALIGN_CENTRE, get_idioma("--Options--"));
		break;
		case 2:
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 250, ALLEGRO_ALIGN_CENTRE, get_idioma("--Exit--"));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 252, ALLEGRO_ALIGN_CENTRE, get_idioma("--Exit--"));
		break;
	}
}

/*
Função "loop" do menu inicial que aguarda uma escolha
*/
void StartMenu()
{
	bool sair = false;
	int tecla = 0;
	int MenuPosition = 0;

	PrintMenu(0);

	al_start_timer(game.timer);
	while(!sair)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(game.fila_eventos, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			game.som = al_load_sample("./data/sound/menu_open.wav");
			al_play_sample(game.som, 2.0, 0.0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
	       // al_rest(0.4); // causa um micro delay, apenas para sincronizar o audio...
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
				case ALLEGRO_KEY_ENTER:
				if(MenuPosition == 0)
				{
					menuSelecaox();
					GameLoop(ev);
					sair = true;
					break;
					//PrintMenu(0);
				}
				else if(MenuPosition == 1) {
						OpcoesMenu();
						tecla = 3;
					}
				else{
					sair = true;
				}
				break;
				case ALLEGRO_KEY_UP:
				tecla = 1;
					//Posição inicial
				if(MenuPosition == 0)
						//ultima posição disponivel
					MenuPosition = 2;
				else
					MenuPosition--;
				break;
			
				case ALLEGRO_KEY_DOWN:
				tecla = 2;
				//ultima posição disponivel
				if(MenuPosition == 2)
						//Posição inicial
					MenuPosition = 0;
				else
					MenuPosition++;
				break;
			}
		}
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			sair = true;
		}
		if (ev.type == ALLEGRO_EVENT_JOYSTICK_AXIS)
		{
			game.som = al_load_sample("./data/sound/menu_open.wav");
			al_play_sample(game.som, 2.0, 0.0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
			if(ev.joystick.axis == 1)
        	{
    	    	if(ev.joystick.pos > 0)
    	    	{
            		tecla = 2;
					//ultima posição disponivel
					if(MenuPosition == 2)
						//Posição inicial
						MenuPosition = 0;
					else
					MenuPosition++;
          		}
            	if(ev.joystick.pos < 0)
            	{
            		tecla = 1;
					if(MenuPosition == 0)
						//ultima posição disponivel
						MenuPosition = 2;
					else
						MenuPosition--;
					
            	}
            } 
		}
		if(ev.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN){
			switch (ev.joystick.button)
			{
				case 2:
				case 9:
					if(MenuPosition == 0)
					{
						menuSelecaox();
						GameLoop(ev);
						sair = true;
						break;
						//PrintMenu(0);
					}
					else if(MenuPosition == 1) {
							OpcoesMenu();
							tecla = 3;
						}
					else{
						sair = true;
					}
				break;
			}
		}

		if (tecla)
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			PrintMenu(MenuPosition);
			tecla = 0;
		}


		al_flip_display();
	}
}
