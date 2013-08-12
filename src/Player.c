#include "Player.h"

void moveDireita(struct Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}

	player->image.x -= 4; // usado para controlar o fundo

	/*if(image.x >= LARGURA + image.frameWidth)
		image.x = 0; */
}

void moveEsquerda(struct Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}

	player->image.x += 4; // usado para controlar o fundo

	/*if(image.x <= image.frameWidth)
		image.x = LARGURA; */
}
