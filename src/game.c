#include "comum.h"
#include "SpriteSheet.h"

void GameLoop()
{
	int width = 600;
	bool sair = false;

	struct ImageSheet image;
	image.x = 600 / 2;
	image.y = 600 / 2;
	image.maxFrame = 6;
	image.curFrame = 0;
	image.frameCount = 0;
	image.frameDelay = 4;
	image.frameWidth = 104;
	image.frameHeight = 147;
	image.image = al_load_bitmap("./data/gb_walk.png");

	al_start_timer(game.timer);
	while(!sair)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(game.fila_eventos, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
			case ALLEGRO_KEY_LEFT:
				break;
			case ALLEGRO_KEY_RIGHT:
				break;
			case ALLEGRO_KEY_UP:
				break;
			case ALLEGRO_KEY_DOWN:
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			if(++image.frameCount >= image.frameDelay)
			{
				if(++image.curFrame >= image.maxFrame)
					image.curFrame = 0;

				image.frameCount = 0;
			}
			image.x += 5;

			if(image.x >= width)
				image.x = 0;
		}

		al_draw_bitmap_region(image.image, image.curFrame * image.frameWidth, 0, image.frameWidth, image.frameHeight, image.x, image.y, 0);

		al_draw_bitmap_region(image.image, image.curFrame * image.frameWidth, 150, image.frameWidth, image.frameHeight, 150, 150, 0);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
}
