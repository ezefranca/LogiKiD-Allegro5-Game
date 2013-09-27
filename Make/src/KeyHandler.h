#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

typedef struct{
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool KeyRight;
}Keys;

void setKeys(Keys *keys, ALLEGRO_EVENT *ev);
void createKeys(Keys *keys);