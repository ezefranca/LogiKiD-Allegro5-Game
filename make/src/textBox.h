<<<<<<< HEAD
=======
#ifndef TEXTBOX_H
#define TEXTBOX_H

>>>>>>> tales
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
	char menina_texto[3][90];
	char texto_generico[5][100];
}Dialogs;

void TextBoxLoad(ALLEGRO_EVENT *ev, char dialog[]);
void TextBoxLoad_matriz(ALLEGRO_EVENT *ev, char *dialog[], int textYPos);
<<<<<<< HEAD
void createDialogs(Dialogs *dialog);
=======
void createDialogs(Dialogs *dialog);

#endif
>>>>>>> tales
