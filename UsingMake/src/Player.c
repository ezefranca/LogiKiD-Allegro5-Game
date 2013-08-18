#include "Player.h"

void CreatePlayer(struct Player *player, int hStartPosition, int wStartPosition)
{
	player->state.direita = false;
	player->state.esquerda = false;
	player->state.sobe = false;
	player->state.desce = false;
	player->state.idleE = false;
	player->state.idleD = true;
	
	player->Image.posInSprite = 0;
	player->Image.x = hStartPosition;
	player->Image.y = wStartPosition;
	player->Image.maxFrame = 6;
	player->Image.curFrame = 0;
	player->Image.frameCount = 0;
	player->Image.frameDelay = 4;
	player->Image.frameWidth = 104;
	player->Image.frameHeight = 147;
	player->Image.image = al_load_bitmap("./data/gb_walk.png");
}

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

void ProcessaMovimentoEsquerda(struct Player *player)
{
	if(player->state.direita != true)
	{
		player->Image.posInSprite = 150;
		player->state.esquerda = true;
		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ProcessaMovimentoDireita(struct Player *player)
{
	if(player->state.esquerda != true)
	{
		player->Image.posInSprite = 0;
		player->state.direita = true;

		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ProcessaMovimentoCima(struct Player *player)
{
	if(player->state.desce != true)
		player->state.sobe = true;
}

void ProcessaMovimentoBaixo(struct Player *player)
{
	if(player->state.sobe != true)
		player->state.desce = true;
}

void ValidaMovimento_CK_UP(struct Player *player)
{
	if(player->state.direita == true)
	{
		player->state.idleD = true;
		player->state.idleE = false;
		player->state.direita = false;

		// reseta os valores dos sprites
		player->Image.curFrame = 0;
		player->Image.frameCount = 0;
	}
	if(player->state.esquerda == true)
	{
		player->state.idleE = true;
		player->state.idleD = false;
		player->state.esquerda = false;

		// reseta os valores dos sprites
		player->Image.curFrame = 0;
		player->Image.frameCount = 0;
	}
	if(player->state.sobe == true)
	{
		player->state.sobe = false;
		player->state.desce = false;
	}
	if(player->state.desce == true)
	{
		player->state.sobe = false;
		player->state.desce = false;
	}
}

void ValidaMovimento_TIMER(struct Player *player)
{
	if(player->state.direita == true)
		moveDireita(player);
	if(player->state.esquerda == true)
		moveEsquerda(player);
	if(player->state.sobe == true)
		moveCima(player);
	if(player->state.desce == true)
		moveBaixo(player);
}

void ValidaMovimento(struct Player *player)
{
	if(player->state.idleE == true)
		al_draw_bitmap_region(player->Image.image, player->Image.frameWidth, 303, player->Image.frameWidth, player->Image.frameHeight, player->Image.x, player->Image.y, 0);
	else if(player->state.idleD == true)
		al_draw_bitmap_region(player->Image.image, 0, 303, player->Image.frameWidth, player->Image.frameHeight, player->Image.x, player->Image.y, 0);
	else
		al_draw_bitmap_region(player->Image.image, player->Image.curFrame * player->Image.frameWidth, player->Image.posInSprite, player->Image.frameWidth, player->Image.frameHeight, player->Image.x, player->Image.y, 0);

}