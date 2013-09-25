#include "Player.h"
#include <stdio.h>

void CreatePlayer(Player *player, int hStartPosition, int wStartPosition)
{
	player->state.direita = false;
	player->state.esquerda = false;
	player->state.sobe = false;
	player->state.desce = false;
	player->state.idleE = false;
	player->state.idleD = true;
	player->state.idleC = false;
	player->state.idleB = false;
	
	player->image.posInSprite = 10;
	player->image.x = hStartPosition;
	player->image.y = wStartPosition;
	player->image.maxFrame = 3;
	player->image.curFrame = 1;
	player->image.frameCount = 1;
	player->image.frameDelay = 3;
	/*
	player->image.frameWidth = 104;
	player->image.frameHeight = 147;
	*/
	player->image.frameWidth = 57;
	player->image.frameHeight = 79;
	player->image.image = al_load_bitmap("./data/images/Player/boy.png");
	
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
	
	if(player->image.y - player->image.frameHeight < 200)
	{
		if(player->image.x < 650)
		{
		player->image.x += 4; // usado para controlar o fundo
		}
	}
	else
	{
		if(player->image.x < 500)
		{
			player->image.x += 4; // usado para controlar o fundo
		}
	}
	
	printf("%d %d \n", player->image.x, player->image.y);

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
	
	if(player->image.x > 200)
	{
	player->image.x -= 4; // usado para controlar o fundo
	}
	printf("%d %d \n", player->image.x, player->image.y);
	/*if(image.x <= image.frameWidth)
		image.x = LARGURA; */
}

void moveCima(Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}
	if(player->image.y > 100)
	{
		player->image.y -= 4;	
	}
	printf("%d %d \n", player->image.x, player->image.y);
	
}

void moveBaixo(Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}
	if(player->image.y < 510 - player->image.frameHeight)
	{
		player->image.y += 4;
		
	}
	printf("%d %d \n", player->image.x, player->image.y);
}

void ProcessaMovimentoEsquerda(Player *player)
{
	if(player->state.direita != true)
	{
		//player->image.posInSprite = 150;
		player->image.posInSprite = player->image.frameHeight*3;
		player->state.esquerda = true;
		
		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ProcessaMovimentoDireita(Player *player)
{
	if(player->state.esquerda != true)
	{
		player->image.posInSprite = player->image.frameHeight;
		player->state.direita = true;
		
		player->state.idleC = false;
		player->state.idleB = false;
		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ProcessaMovimentoCima(Player *player)
{
	if(player->state.desce != true)
	{
		player->image.posInSprite = 0;
		player->state.sobe = true;
		
		player->state.idleC = false;
		player->state.idleB = false;
		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ProcessaMovimentoBaixo(Player *player)
{
	if(player->state.sobe != true)
	{
		player->image.posInSprite = player->image.frameHeight*2;
		player->state.desce = true;
		
		player->state.idleC = false;
		player->state.idleB = false;
		player->state.idleE = false;
		player->state.idleD = false;
	}
}

void ValidaMovimento_CK_UP(Player *player)
{
	if(player->state.direita == true)
	{
		player->state.idleD = true;
		player->state.idleE = false;
		player->state.idleC = false;
		player->state.idleB = false;
		player->state.direita = false;

		// reseta os valores dos sprites
		player->image.curFrame = 0;
		player->image.frameCount = 0;
	}
	if(player->state.esquerda == true)
	{
		player->state.idleE = true;
		player->state.idleD = false;
		player->state.idleC = false;
		player->state.idleB = false;
		player->state.esquerda = false;

		// reseta os valores dos sprites
		player->image.curFrame = 0;
		player->image.frameCount = 0;
	}
	if(player->state.sobe == true)
	{
		player->state.idleC = true;
		player->state.idleB = false;
		player->state.idleE = false;
		player->state.idleD = false;
		player->state.sobe = false;
		
		// reseta os valores dos sprites
		player->image.curFrame = 0;
		player->image.frameCount = 0;	
		
		
	}
	if(player->state.desce == true)
	{
		player->state.idleB = true;
		player->state.idleC = false;		
		player->state.idleD = false;
		player->state.idleE = false;
		player->state.desce = false;

		// reseta os valores dos sprites
		player->image.curFrame = 0;
		player->image.frameCount = 0;
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
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, player->image.frameHeight*3, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
	else if(player->state.idleD == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, player->image.frameHeight, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
	else if(player->state.idleB == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, player->image.frameHeight*2, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
	else if(player->state.idleC == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, 0, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
	else
	{
		al_draw_bitmap_region(player->image.image, player->image.curFrame * player->image.frameWidth, player->image.posInSprite, player->image.frameWidth, player->image.frameHeight, player->image.x, player->image.y, 0);
		// play no audio...
		al_play_sample(player->footstep, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}