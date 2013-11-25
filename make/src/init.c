/*
 * Inicializa os sistemas basicos do Allegro 5
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include "comum.h"
#include "config.h"

<<<<<<< HEAD

 bool inicializar()
 {
=======
/*Inicializa recursos do Allegro */
bool inicializar()
{
>>>>>>> 70cc5e6336c0cff54478cca21347d855ed040708
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
    al_set_window_title(game.janela, get_idioma("Integrator Project II - Senac - CCB"));

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
    if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(game.janela);
        return -1;
    }

    if (!al_set_system_mouse_cursor(game.janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(game.janela);
        return -1;
    }

    game.fonte = al_load_font("data/circuito.ttf", 50, 10);
    game.fonte_menu = al_load_font("data/sourcecode.ttf", 20, 20);
    game.fonte_logo = al_load_font("data/256BYTES.TTF", 150, 10);
    game.fonteKeys = al_load_font("data/keys.otf", 50, 10);

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

if(!load_configuracao("data/config/config.conf")){
    fprintf(stderr, "Falha ao carregar configuração!\n");
    return false;
}

    //Carrega idioma padrão.
if(!load_idioma("data/idiomas/pt_br.conf")){
    fprintf(stderr, "Falha ao carregar idioma padrão (Português)!\n");
    return false;
}

    //Carrega configuracao de usuario.
if(!load_config_user("data/config/user.conf")){
    fprintf(stderr, "Falha ao carregar configuração de usuário!\n");
    return false;
}


game.mute = 1;
    //Aqui você pode implementar um savestate
    // 42 é o valor do tutorial (instrucoes de jogo)
game.level = 42;
al_register_event_source(game.fila_eventos, al_get_mouse_event_source());
al_register_event_source(game.fila_eventos, al_get_timer_event_source(game.timer));
al_register_event_source(game.fila_eventos, al_get_keyboard_event_source());
al_register_event_source(game.fila_eventos, al_get_display_event_source(game.janela));

return true;
}
