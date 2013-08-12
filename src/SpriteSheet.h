#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

struct ImageSheet
{
	ALLEGRO_BITMAP *image;

	int x;
	int y;

	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
};
