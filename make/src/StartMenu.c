#include "StartMenu.h"
#include "comum.h"
#include "gameloop.h"



void PrintMenu(int MenuPosition)
{
	ALLEGRO_BITMAP *menu_fundo = al_load_bitmap("./data/levels/menu/BG3.png");
	al_draw_bitmap(menu_fundo, 0, 0, 0);
	//al_draw_scaled_bitmap(fundo, 0, 0, 640, 480, 0, 0, 800, 600, 0);
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 302, ALLEGRO_ALIGN_CENTRE, "--------------------------");
	al_draw_text(game.fonte, al_map_rgb(0, 255, 0), 800 / 2, 305, ALLEGRO_ALIGN_CENTRE, "--------------------------");
	al_draw_text(game.fonte_logo, al_map_rgb(0, 0, 0), 800 / 2, 350, ALLEGRO_ALIGN_CENTRE, "LogiKid");
	al_draw_text(game.fonte_logo, al_map_rgb(0, 255, 0), 800 / 2, 356, ALLEGRO_ALIGN_CENTRE, "LogiKid");
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, "Iniciar jogo");
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 52, ALLEGRO_ALIGN_CENTRE, "Iniciar jogo");
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 150, ALLEGRO_ALIGN_CENTRE, "Sair");
	al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, 152, ALLEGRO_ALIGN_CENTRE, "Sair");

	switch(MenuPosition)
	{

		case 0:
			al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, "--Iniciar jogo--");
			al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 52, ALLEGRO_ALIGN_CENTRE, "--Iniciar jogo--");
			break;
		case 1:
    		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 150, ALLEGRO_ALIGN_CENTRE, "--Sair--");
    		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, 152, ALLEGRO_ALIGN_CENTRE, "--Sair--");
    		break;
	}
}

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
					GameLoop_Fase1(ev);
					PrintMenu(0);
				}
				else{
					sair = true;
				}
				break;
            case ALLEGRO_KEY_UP:
            	tecla = 1;
            	if(MenuPosition == 0)
	            	MenuPosition = 1;
	            else if(MenuPosition == 1)
	            	MenuPosition = 0;
            	else
            		MenuPosition++;
                break;
            case ALLEGRO_KEY_DOWN:
            	tecla = 2;
            	if(MenuPosition == 1)
	            	MenuPosition = 0;
	            else if(MenuPosition == 0)
	            	MenuPosition = 1;
            	else
            		MenuPosition--;
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

            PrintMenu(MenuPosition);

            tecla = 0;
        }


        al_flip_display();
	}
}