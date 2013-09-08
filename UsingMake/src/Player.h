/*
 * Contem as informações do sprite sheet
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct
{
	ALLEGRO_BITMAP *image;

	int x;
	int y;

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
	bool direita, esquerda;
	bool sobe, desce;
	bool idleE, idleD;
}State;

typedef struct
{
	int lgAND, lgOr, lgNAND, lgNOR;
	int lgNEG, lgXOR, lgXNOR;
}LogicGates;

typedef struct
{
	State state;
	Image image;
	LogicGates lGates;
}Player;

struct Player
{
	int points;
	int level;

	struct
	{
		bool direita, esquerda;
		bool sobe, desce;
		bool idleE, idleD;
	}state;

	struct
	{
		ALLEGRO_BITMAP *image;

		int x;
		int y;

		int posInSprite;
		int maxFrame;
		int curFrame;
		int frameCount;
		int frameDelay;
		int frameWidth;
		int frameHeight;
	}Image;
	
	struct
	{
		int lgAND, lgOr, lgNAND, lgNOR;
		int lgNEG, lgXOR, lgXNOR;
		
	}LogicGates;
};

void CreatePlayer(struct Player *player, int hStartPosition, int wStartPosition);
void moveDireita(struct Player *player);
void moveEsquerda(struct Player *player);
void moveCima(struct Player *player);
void moveBaixo(struct Player *player);
void ProcessaMovimentoEsquerda(struct Player *player);
void ProcessaMovimentoDireita(struct Player *player);
void ProcessaMovimentoCima(struct Player *player);
void ProcessaMovimentoBaixo(struct Player *player);
void ValidaMovimento_CK_UP(struct Player *player);
void ValidaMovimento_TIMER(struct Player *player);
void ValidaMovimento(struct Player *player);