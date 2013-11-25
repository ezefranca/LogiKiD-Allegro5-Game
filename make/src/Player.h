/*
 * Contem as informações do sprite sheet
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

 #ifndef PLAYER_H
 #define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

 typedef struct
 {
 	ALLEGRO_BITMAP *image;

 	int posInSprite;
 	int maxFrame;
 	int curFrame;
 	int frameCount;
 	int frameDelay;
 	int frameWidth;
 	int frameHeight;
 }Image;

 typedef struct
 {
 	int x;
 	int y;
 	int speed;
 	bool direita, esquerda;
 	bool sobe, desce;
 	bool idleE, idleD, idleC, idleB;
 }State;

 typedef struct
 {
 	int lgAND, lgOR, lgNAND, lgNOR;
 	int lgNOT, lgXOR, lgXNOR;
 }LogicGates;

 typedef struct
 {
 	ALLEGRO_SAMPLE *footstep;
 	ALLEGRO_FONT *play_font;
 	State state;
 	Image image;
 	LogicGates lGates;
 	int chances;
 }Player;


 typedef struct{
 	bool keyUp;
 	bool keyDown;
 	bool keyLeft;
 	bool keyRight;
 }Keys;

 void CreatePlayer(Player *player, int hStartPosition, int wStartPosition, int spritePersonagem);
 void moveDireita(Player *player);
 void moveEsquerda(Player *player);
 void moveCima(Player *player);
 void moveBaixo(Player *player);
 void ProcessaMovimentoEsquerda(Player *player);
 void ProcessaMovimentoDireita(Player *player);
 void ProcessaMovimentoCima(Player *player);
 void ProcessaMovimentoBaixo(Player *player);
 void ValidaMovimento_CK_UP(Player *player);
 void ValidaMovimento(Player *player);

 void setKeys(Keys *keys, Player *player, ALLEGRO_EVENT *ev);
 void createKeys(Keys *keys);
 void movePlayer(Keys *keys, Player *player);

#endif