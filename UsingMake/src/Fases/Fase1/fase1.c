#include "fase1.h"
#include "../../comum.h"
#include "../../Player.h"
#include "../../ItensMenu.h"
#include "../../KeyHandler.h"

ALLEGRO_BITMAP *SetBackGroundImage(const char *bk_path)
{
	return al_load_bitmap(bk_path);
}

void GameLoop_Fase1(ALLEGRO_EVENT ev)
{
	bool sair = false;
	Gates gate = 99;
	
	Keys *keys = malloc(sizeof(Player));
	Player *player = malloc(sizeof(Player));
	Player *testeObjeto = malloc(sizeof(Player)); 
	testeObjeto->image.image = al_load_bitmap("./data/images/Objects/PC.png");  

						
	/* Adiciona as portas logicas... */
	player->lGates.lgAND = 0;
	player->lGates.lgOR = 0;
	player->lGates.lgNAND = 0;
	player->lGates.lgNOR = 5;
	player->lGates.lgXOR = 0;
	player->lGates.lgXNOR = 0;
	player->lGates.lgNOT = 0;

	CreatePlayer(player, ALTURA/2, LARGURA/2);

	ALLEGRO_BITMAP *fundo = SetBackGroundImage("./data/levels/fase2.jpg");
	
	//al_start_timer(game.timer);
	while(!sair)
	{
		//ALLEGRO_EVENT ev;
		al_wait_for_event(game.fila_eventos, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			sair = true;

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
			case ALLEGRO_KEY_LEFT:
				ProcessaMovimentoEsquerda(player);			
				break;
			case ALLEGRO_KEY_RIGHT:
				ProcessaMovimentoDireita(player);
				break;
			case ALLEGRO_KEY_UP:
				ProcessaMovimentoCima(player);
				break;
			case ALLEGRO_KEY_DOWN:
				ProcessaMovimentoBaixo(player);
				break;
				
			// inicializa o MENU de portas...
			case ALLEGRO_KEY_M:
				gate = MenuLoad(&ev, player);
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			ValidaMovimento_CK_UP(player);
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			ValidaMovimento_TIMER(player);
		}
		/* teste fundo */
		al_draw_scaled_bitmap(fundo, 0, 0, 640, 480, 0, 0, 800, 600, 0);
		
		/* teste de um Objeto na tela  */
		al_draw_bitmap(testeObjeto->image.image, 600, 200, 0);
	

		ValidaMovimento(player);
		
		/* Apenas para teste... inicio*/
		switch(gate)
		{
		case NOT:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "NOT");
			break;
		case AND:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "AND");
			break;
		case OR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "OR");
			break;
		case NAND:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "NAND");
			break;
		case NOR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "NOR");
			break;
		case XOR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "XOR");
			break;
		case XNOR:
			al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 150, 140, ALLEGRO_ALIGN_CENTRE, "XNOR");
			break;
		default:
			if(gate == 66)
				al_draw_text(game.fonte_menu, al_map_rgb(255, 0, 0), 400, 240, ALLEGRO_ALIGN_CENTRE, "nao tem mais portas :(");
			break;	
		}
		/* Fim dos testes... */
		
		al_flip_display();
		//al_clear_to_color(al_map_rgb(0,0,0));
	}
	free(keys);
	free(player);
	free(testeObjeto);
}