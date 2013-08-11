#include "include/game.h"
#include "include/config.h"
#include "include/engine.h"

int main(int argc, char **argv)
{
    Jogo *game = (Jogo*)malloc(sizeof(Jogo));
    
    if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
	LoadConfig(game, "config.ini");
	
	if (game->FullScreen == 1)
	    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	else
	    al_set_new_display_flags(ALLEGRO_WINDOWED);
	    
	game->janela = al_create_display(game->altura,game->largura);
	
	StartGame(game);
    
    return 0;
}
