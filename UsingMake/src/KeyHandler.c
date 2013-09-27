#include "Player.h"
//#include "comum.h"
#include "KeyHandler.h"
#include "ItensMenu.h"
#include <stdio.h>

void setKeys(Keys *keys, ALLEGR0_EVENT *ev){
	
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_LEFT;
			keys.keyLeft = true;
			printf("Virou esquerda\n");
			break;
		case ALLEGRO_KEY_RIGHT:
			keys.keyRight = true;
			break;
		case ALLEGRO_KEY_UP:
			keys.keyUp = true;
			break;
		case ALLEGRO_KEY_DOWN:
			keys.keyDown = true;
			break;
		}
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_LEFT;
			keys.keyLeft = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			keys.keyRight = false;
			break;
		case ALLEGRO_KEY_UP:
			keys.keyUp = false;
			break;
		case ALLEGRO_KEY_DOWN:
			keys.keyDown = false;
			break;
		}
	}
}

void createKeys(Keys *keys){
	keys.keyUp = false;
	keys.keyDown = false;
	keys.keyLeft = false;
	keys.keyRight = false;
}