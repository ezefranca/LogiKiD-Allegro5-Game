#include "Idioma.h"
#include "../../src/comum.h"
#include "../../src/config.h"
#include "../../src/gameloop.h"
#include "selecaomenu.h"

idioma id;

void print_idioma_disponivel_position(int MenuPosition){
	if(id.tamanho > 0) {
		al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, (MenuPosition * 100) + 150, ALLEGRO_ALIGN_CENTRE, get_idioma(id.linguagem[MenuPosition]));
		al_draw_text(game.fonte, al_map_rgb(255, 255, 0), 800 / 2, (MenuPosition * 100) + 152, ALLEGRO_ALIGN_CENTRE, get_idioma(id.linguagem[MenuPosition]));
	}
}
void print_idioma_disponivel(){
	int i;
	
	if(id.tamanho > 0) {
		for(i = 0; i < id.tamanho; i++){
			al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, (i * 100) + 150, ALLEGRO_ALIGN_CENTRE, get_idioma(id.linguagem[i]));
			al_draw_text(game.fonte, al_map_rgb(255, 255, 255), 800 / 2, (i * 100) + 152, ALLEGRO_ALIGN_CENTRE, get_idioma(id.linguagem[i]));
		}
	}
}

void PrintIdioma(int MenuPosition)
{
	ALLEGRO_BITMAP *menu_fundo = al_load_bitmap("./data/levels/tutorial/tutorialbase.png");
	al_draw_bitmap(menu_fundo, 0, 0, 0);
	//al_draw_scaled_bitmap(fundo, 0, 0, 640, 480, 0, 0, 800, 600, 0);
	//al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 200, 302, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	//al_draw_text(game.fonte, al_map_rgb(0, 255, 0), 200, 305, ALLEGRO_ALIGN_CENTRE, get_idioma("--------------------------"));
	al_draw_text(game.fonte, al_map_rgb(0, 0, 0), 800 / 2, 50, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));
	al_draw_text(game.fonte, al_map_rgb(150, 150, 150), 800 / 2, 52, ALLEGRO_ALIGN_CENTRE, get_idioma("Language"));

	print_idioma_disponivel();

	print_idioma_disponivel_position(MenuPosition);
}




idioma aloca_idioma(){
	idioma idi;
	int t, largura, character_len, count, *tamanhos, i;
    char *idiomas = get_configuracao("idiomas");
    char **linguagens;

    largura = strlen(idiomas);

    count = 1;

	for(i = 0; i < largura; i++){
		if(idiomas[i] == ';') {
			count++;
		}
	}

	
	linguagens = malloc(count * sizeof (char *));
	tamanhos = malloc(count * sizeof(int));
	
	count = 0;
	t = 0;

	for(i = 0; i < largura; i++){
		if(idiomas[i] == ';'){
			t = i - t - count;
			tamanhos[count] = t; 
			count++;
		}
		if(idiomas[i] != ';' && i + 1 == largura){
			tamanhos[count] = i - t - count + 1;
		}
	}
	
	for(i = 0; i <= count; i++) {
		linguagens[i] = malloc((tamanhos[i] + 1) * sizeof(char));
	}

	count = 0;
	character_len = 0;
	
	for(i = 0; i < largura; i++){
		if(idiomas[i] == ';'){
			linguagens[count][character_len] = '\0';
			count++;
			character_len = 0;
		}
		else {
			linguagens[count][character_len] = idiomas[i];
			character_len++;
		}
		if(i + 1 == largura){
			linguagens[count][character_len] = '\0';
		}
	}


	free(tamanhos);
	
	idi.tamanho = count + 1;
    idi.linguagem = linguagens;

    return idi;
}




void free_idioma(idioma *id){
	int i;
	if(id->tamanho > 0) {
		for(i = 0; i < id->tamanho; i++){
			free(id->linguagem[i]);	
		}
	}
}

int string_size(char *c) {
	int i = 0;
	for(i = 0; c[i] != '\0'; i++);
	return i;
}

void IdiomaMenu()
{
	bool sair = false;
	int tecla = 0;
	int MenuPosition = 0;
	
	//char string;

	id = aloca_idioma();

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
					//limpa_idioma();
					load_idioma(id.linguagem[MenuPosition]);
					//update_config_user("idioma", id.linguagem[MenuPosition]);
					sair = true;
					tecla = 0;
					break;
				case ALLEGRO_KEY_UP:
					tecla = 1;
					//Posição inicial
					if(MenuPosition == 0)
						//ultima posição disponivel
						MenuPosition = id.tamanho - 1;
					else
						MenuPosition--;
					printf("conta %d", MenuPosition);
					break;
				break;
				case ALLEGRO_KEY_DOWN:
					tecla = 2;
					//ultima posição disponivel
					if(MenuPosition == id.tamanho - 1)
						//Posição inicial
						MenuPosition = 0;
					else
						MenuPosition++;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			free_idioma(&id);
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
	free_idioma(&id);
}