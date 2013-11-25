#include "Opcoes.h"
#include "Idioma.h"
#include "../../src/comum.h"
#include "../../src/config.h"
#include "../../src/gameloop.h"
//#include "../../src/selecaomenu.h"

void PrintOpcoes(int MenuPosition)
{
	ALLEGRO_BITMAP *menu_fundo = al_load_bitmap("./data/levels/tutorial/tutorialbase.png");
	al_draw_bitmap(menu_fundo, 0, 0, 0);
	//al_draw_scaled_bitmap(fundo, 0, 0, 640, 480, 0, 0, 800, 600, 0);
	//al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 200, 302, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	//al_draw_text(game.fonte, al_map_rgb(0, 255, 0), 200, 305, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, get_idioma("Options"));
	al_draw_text(game.fonte, al_map_rgb(150, 150, 150), 800 / 2, 52, ALLEGRO_ALIGN_CENTRE, get_idioma("Options"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 150, ALLEGRO_ALIGN_CENTRE, get_idioma("Choose your character"));
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 152, ALLEGRO_ALIGN_CENTRE, get_idioma("Choose your character"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 250, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 252, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 350, ALLEGRO_ALIGN_CENTRE, get_idioma("Save and Go back"));
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 352, ALLEGRO_ALIGN_CENTRE, get_idioma("Save and Go back"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 450, ALLEGRO_ALIGN_CENTRE, get_idioma("Just Go back"));
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 452, ALLEGRO_ALIGN_CENTRE, get_idioma("Just Go back"));

	switch(MenuPosition)
	{
		case 0:
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 150, ALLEGRO_ALIGN_CENTRE, get_idioma("Choose your character"));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 152, ALLEGRO_ALIGN_CENTRE, get_idioma("Choose your character"));
		break;
		case 1:
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 250, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 252, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));
		break;
		case 2:
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 350, ALLEGRO_ALIGN_CENTRE, get_idioma("Save and Go back"));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 352, ALLEGRO_ALIGN_CENTRE, get_idioma("Save and Go back"));
		break;
		case 3:
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 450, ALLEGRO_ALIGN_CENTRE, get_idioma("Just Go back"));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 452, ALLEGRO_ALIGN_CENTRE, get_idioma("Just Go back"));
		break;
	}
}

void OpcoesMenu()
{
	bool sair = false;
	int tecla = 0;
	int MenuPosition = 0;

	PrintOpcoes(0);

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
					//SelecaoMenu();
					tecla = 4;
				}
				else if(MenuPosition == 1){
					IdiomaMenu();
					tecla = 3;
				}
				else if(MenuPosition == 2){
					salva_config_user("data/config/user.conf");
					sair = true;
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
						MenuPosition = 3;
					else
						MenuPosition--;
					break;
				break;
				case ALLEGRO_KEY_DOWN:
				tecla = 2;
				//ultima posição disponivel
					if(MenuPosition == 3)
						//Posição inicial
						MenuPosition = 0;
					else
						MenuPosition++;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			sair = true;
		}

		if (tecla)
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			PrintOpcoes(MenuPosition);
			tecla = 0;
		}


		al_flip_display();
	}
}