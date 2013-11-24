#include "Idioma.h"
#include "../../src/comum.h"
#include "../../src/config.h"
#include "../../src/gameloop.h"
#include "selecaomenu.h"

idioma id;

void PrintIdioma(int MenuPosition)
{
	ALLEGRO_BITMAP *menu_fundo = al_load_bitmap("./data/levels/tutorial/tutorialbase.png");
	al_draw_bitmap(menu_fundo, 0, 0, 0);
	//al_draw_scaled_bitmap(fundo, 0, 0, 640, 480, 0, 0, 800, 600, 0);
	//al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 200, 302, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	//al_draw_text(game.fonte, al_map_rgb(0, 255, 0), 200, 305, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));
	al_draw_text(game.fonte, al_map_rgb(150, 150, 150), 800 / 2, 52, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));

	//print_idioma_disponivel(id);

	//print_idioma_disponivel_position(MenuPosition, id);
}

void print_idioma_disponivel(idioma id){
	/*int i, count;
	char *idiomas = get_configuracao("idiomas");
	
	count = 1;

	for(i = 0; i < strlen(idiomas); i++){
		if(idiomas[i] == ';') {
			count++;
		}
	}*/

}
/*

void *aloca_idioma(){
	idioma *i = malloc(sizeof (idioma));
    char *idiomas = get_configuracao("idiomas");
    char **linguagens;

    count = 1;

	for(i = 0; i < strlen(idiomas); i++){
		if(idiomas[i] == ';') {
			count++;
		}
	}

	linguagens = malloc(count * sizeof (char *));

	count = 0;
	for(i = 0; i < strlen(idiomas); i++){
		if(idiomas[i] == ';'){
			count++;
		}
		linguagens[count][i] = idiomas[i];
		linguagens[count] = malloc(sizeof(char));

	}


	i->tamanho = count;
    i->linguagem = linguagens;
    return i;
}*/



/*
void print_idioma_disponivel_position(int MenuPosition, idioma id){
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, MenuPosition + 150, ALLEGRO_ALIGN_CENTRE, idioma[MenuPosition]);
	al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, MenuPosition + 152, ALLEGRO_ALIGN_CENTRE, idioma[MenuPosition]);
}*/

void free_idioma(){

}

void IdiomaMenu()
{
	bool sair = false;
	int tecla = 0;
	int MenuPosition = 0;

	//aloca_idioma(&id);

	PrintIdioma(0);

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
					//IdiomaMenu();
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
			PrintIdioma(MenuPosition);
			tecla = 0;
		}


		al_flip_display();
	}

	free_idioma();
}