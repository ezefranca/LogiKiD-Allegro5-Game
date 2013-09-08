#include "ItensMenu.h"
#include "comum.h"

void ChengePositionChoiceItem()
{

}

void MoveItemPointer(int tecla)
{
	switch(tecla)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}

void ItensMenu_Init(ALLEGRO_EVENT evento)
{
	bool sair = false;
	int tecla = 0;
	
	while(!sair)
	{
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
		
		if(tecla)
		{
		}
		
		al_flip_display();
	}
}