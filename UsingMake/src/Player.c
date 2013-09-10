#include "Player.h"

void CreatePlayer(Player *player, int hStartPosition, int wStartPosition)
{
	player->state.direita = false;
	player->state.esquerda = false;
	player->state.sobe = false;
	player->state.desce = false;
	player->state.idleE = false;
	player->state.idleD = true;
	
	player->image.posInSprite = 0;
	player->image.x = hStartPosition;
	player->image.y = wStartPosition;
	player->image.maxFrame = 6;
	player->image.curFrame = 0;
	player->image.frameCount = 0;
	player->image.frameDelay = 4;
	player->image.frameWidth = 104;
	player->image.frameHeight = 147;
	player->image.image = al_load_bitmap("./data/images/Player/gb_walk.png");
	
	player->footstep = al_load_sample("./data/sound/footstep.wav");
}

void moveDireita(Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}

	player->image.x += 4; // usado para controlar o fundo

	/*if(image.x >= LARGURA + image.frameWidth)
		image.x = 0; */
}

void moveEsquerda(Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}

	player->image.x -= 4; // usado para controlar o fundo

	/*if(image.x <= image.frameWidth)
		image.x = LARGURA; */
}

void moveCima(Player *player)
{
	player->image.y -= 4;
}

void moveBaixo(Player *player)
{
	player->image.y += 4;
}

void ProcessaMovimentoEsquerda(Player *player)
{
	if(player->state.direita != true)
	{
		player->image.posInSprite = 150;
		player->state.esquerda = true;
		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ProcessaMovimentoDireita(Player *player)
{
	if(player->state.esquerda != true)
	{
		player->image.posInSprite = 0;
		player->state.direita = true;

		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ProcessaMovimentoCima(Player *player)
{
	if(player->state.desce != true)
		player->state.sobe = true;
}

void ProcessaMovimentoBaixo(Player *player)
{
	if(player->state.sobe != true)
		player->state.desce = true;
}

void ValidaMovimento_CK_UP(Player *player)
{
	if(player->state.direita == true)
	{
		player->state.idleD = true;
		player->state.idleE = false;
		player->state.direita = false;

		// reseta os valores dos sprites
		player->image.curFrame = 0;
		player->image.frameCount = 0;
	}
	if(player->state.esquerda == true)
	{
		player->state.idleE = true;
		player->state.idleD = false;
		player->state.esquerda = false;

		// reseta os valores dos sprites
		player->image.curFrame = 0;
		player->image.frameCount = 0;
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

void ValidaMovimento_TIMER(Player *player)
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

void ValidaMovimento(Player *player)
{
	if(player->state.idleE == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, 303, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
	else if(player->state.idleD == true)
		al_draw_bitmap_region(player->image.image, 0, 303, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
	else
	{
		al_draw_bitmap_region(player->image.image, player->image.curFrame * player->image.frameWidth, player->image.posInSprite, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
		// play no audio...
		al_play_sample(player->footstep, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}