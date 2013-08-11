#include "include/config.h"

void LoadConfig(Jogo *game, const char* FileName)
{
    game->conf = al_load_config_file("./data/config.ini");	
	if(game->conf == NULL)
	{
	    game->conf=al_create_config();
	    al_set_config_value(game->conf, "Game", "fullscreen", "1");
	    //al_set_config_value(game->conf, "Game", "fps", "0");
	    al_set_config_value(game->conf, "Game", "vol_musica", "5");
	    al_set_config_value(game->conf, "Game", "vol_voz", "5");
	    al_set_config_value(game->conf, "Game", "altura", "800");
	    al_set_config_value(game->conf, "Game", "largura", "600");
	    al_save_config_file("./data/config.ini", game->conf);
	    
	    ReadConfig(game);
    }
    else
        ReadConfig(game);
}

void ReadConfig(Jogo* game)
{
    game->FullScreen = atoi(al_get_config_value(game->conf, "Game", "fullscreen"));
    //game->fps = atoi(al_get_config_value(game->conf, "Game", "fps"));
    game->VolumeMusica = atoi(al_get_config_value(game->conf, "Game", "vol_musica"));
    game->VolumeVoz = atoi(al_get_config_value(game->conf, "Game", "vol_voz"));
    game->altura = atoi(al_get_config_value(game->conf, "Game", "altura"));
    game->largura = atoi(al_get_config_value(game->conf, "Game", "largura"));
}
