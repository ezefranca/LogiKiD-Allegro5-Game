/*
 * Inicializa os sistemas basicos do Allegro 5
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include "comum.h"

bool inicializar()
{
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }

    al_init_font_addon();
    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return false;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }

    game.janela = al_create_display(ALTURA, LARGURA);
    if (!game.janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
    al_set_window_title(game.janela, "Study");

    game.fila_eventos = al_create_event_queue();
    if (!game.fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(game.janela);
        return false;
    }

    game.timer = al_create_timer(2.0/60);
    if (!game.timer)
    {
    	fprintf(stderr, "Falha ao criar timer.\n");
        al_destroy_event_queue(game.fila_eventos);
        al_destroy_display(game.janela);
        return false;
    }
    
    game.fonte = al_load_font("data/circuito.ttf", 70, 10);
    game.fonte_menu = al_load_font("data/terminal.ttf", 20, 10);
    if (!game.fonte)
    {
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return false;
    }
    
    if(!al_install_audio())
    {
    	fprintf(stderr, "Falha ao inicializar o audio.\n");
      	return -1;
   	}
    
    if(!al_init_acodec_addon())
    {
      	fprintf(stderr, "Falha ao iniciar o audio codec.!\n");
    	return -1;
    }
    
    if (!al_reserve_samples(1))
    {
        fprintf(stderr, "Falha ao alocar canais de audio.\n");
        return false;
    }

    al_register_event_source(game.fila_eventos, al_get_timer_event_source(game.timer));
    al_register_event_source(game.fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(game.fila_eventos, al_get_display_event_source(game.janela));

    return true;
}
