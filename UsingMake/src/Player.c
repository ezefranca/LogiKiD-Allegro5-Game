#include "Player.h"

void moveDireita(struct Player *player)
{
	if(++player->Image.frameCount >= player->Image.frameDelay)
	{
		if(++player->Image.curFrame >= player->Image.maxFrame)
			player->Image.curFrame = 0;

		player->Image.frameCount = 0;
	}

	player->Image.x += 4; // usado para controlar o fundo

	/*if(image.x >= LARGURA + image.frameWidth)
		image.x = 0; */
}

void moveEsquerda(struct Player *player)
{
	if(++player->Image.frameCount >= player->Image.frameDelay)
	{
		if(++player->Image.curFrame >= player->Image.maxFrame)
			player->Image.curFrame = 0;

		player->Image.frameCount = 0;
	}

	player->Image.x -= 4; // usado para controlar o fundo

	/*if(image.x <= image.frameWidth)
		image.x = LARGURA; */
}

void moveCima(struct Player *player)
{
	player->Image.y -= 4;
}

void moveBaixo(struct Player *player)
{
	player->Image.y += 4;
}
