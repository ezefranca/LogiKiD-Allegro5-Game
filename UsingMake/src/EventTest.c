#include "EventTest.h"
#include "comum.h"

void StartEventTest(ALLEGRO_EVENT evento)
{
	bool sair = false;
	int tecla = 0;
	
	while(!sair)
	{
		al_wait_for_event(game.fila_eventos, &evento);
		
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
        	switch(evento.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
            case ALLEGRO_KEY_UP:
            	tecla = 1;
                break;
            case ALLEGRO_KEY_DOWN:
            	tecla = 2;
                break;
            case ALLEGRO_KEY_LEFT:
                tecla = 3;
                break;
            case ALLEGRO_KEY_RIGHT:
                tecla = 4;
                break;
            }
        }
        else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
        	sair = true;
        }
 
        if (tecla)
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
 
            switch (tecla)
            {
            case 1:
            	al_draw_text(game.fonte, al_map_rgb(255, 0, 0), 800 / 2, 90, ALLEGRO_ALIGN_CENTRE, "CIMA");
                break;
            case 2:
                al_draw_text(game.fonte, al_map_rgb(255, 0, 0), 800 / 2, 90, ALLEGRO_ALIGN_CENTRE, "BAIXO");
                break;
            case 3:
            	al_draw_text(game.fonte, al_map_rgb(255, 0, 0), 800 / 2, 90, ALLEGRO_ALIGN_CENTRE, "ESQUERDA");
                break;
            case 4:
            	al_draw_text(game.fonte, al_map_rgb(255, 0, 0), 800 / 2, 90, ALLEGRO_ALIGN_CENTRE, "DIREITA");
                break;
            }
 
            tecla = 0;
        }
 
        al_flip_display();
	}
}