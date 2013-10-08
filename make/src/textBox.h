#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
  
typedef struct {
	char menina_texto_1[90];
	char computador_texto_1[90];
	char computador_matriz[3][90];
}Dialogs;

void TextBoxLoad(ALLEGRO_EVENT *ev, char dialog[]);
void TextBoxLoad_matriz(ALLEGRO_EVENT *ev, char *dialog[], int textYPos);
void createDialogs(Dialogs *dialog);