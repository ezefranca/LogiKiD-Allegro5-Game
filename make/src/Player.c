#include "Player.h"
#include "comum.h"
#include "ItensMenu.h"
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
	player->state.speed = 4;
	
	player->image.posInSprite = 10;
	player->state.x = hStartPosition;
	player->state.y = wStartPosition;
	player->image.maxFrame = 3;
	player->image.curFrame = 1;
	player->image.frameCount = 1;
	player->image.frameDelay = 3;
	player->image.frameWidth = 57;
	player->image.frameHeight = 79;
	player->image.image = al_load_bitmap("./data/images/Player/boy.png");
	player->play_font = al_load_font("data/circuito.ttf", 50, 10);
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
	printf("x: %d, y: %d \n", player->state.x, player->state.y);
}

void moveEsquerda(Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}
	printf("x: %d, y: %d \n", player->state.x, player->state.y);
}

void moveCima(Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}
	printf("x: %d, y: %d \n", player->state.x, player->state.y);
	
}

void moveBaixo(Player *player)
{
	if(++player->image.frameCount >= player->image.frameDelay)
	{
		if(++player->image.curFrame >= player->image.maxFrame)
			player->image.curFrame = 0;

		player->image.frameCount = 0;
	}
	printf("x: %d, y: %d \n", player->state.x, player->state.y);
}

void ProcessaMovimentoEsquerda(Player *player)
{
	if(player->state.direita != true)
	{
		player->image.posInSprite = player->image.frameHeight*3;
		player->state.esquerda = true;
		
		player->state.idleE = false;
		player->state.idleD = false;
		player->state.idleB = false;
		player->state.idleC = false;
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

void ValidaMovimento(Player *player)
{	
	if(player->state.idleD == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, player->image.frameHeight, player->image.frameWidth, player->image.frameHeight, player->state.x, player->state.y, 0);
	else if(player->state.idleE == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, player->image.frameHeight*3, player->image.frameWidth, player->image.frameHeight, player->state.x, player->state.y, 0);
	else if(player->state.idleB == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, player->image.frameHeight*2, player->image.frameWidth, player->image.frameHeight, player->state.x, player->state.y, 0);
	else if(player->state.idleC == true)
		al_draw_bitmap_region(player->image.image, player->image.frameWidth, 0, player->image.frameWidth, player->image.frameHeight, player->state.x, player->state.y, 0);
	else
	{
		al_draw_bitmap_region(player->image.image, player->image.curFrame * player->image.frameWidth, player->image.posInSprite, player->image.frameWidth, player->image.frameHeight, player->state.x, player->state.y, 0);
		// play no audio...
		al_play_sample(player->footstep, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void createKeys(Keys *keys)
{
	keys->keyUp = false;
	keys->keyDown = false;
	keys->keyLeft = false;
	keys->keyRight = false;
}

void setKeys(Keys *keys, Player *player, ALLEGRO_EVENT *ev)
{	
	if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev->keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
		case ALLEGRO_KEY_LEFT:
			keys->keyLeft = true;
			break;
		case ALLEGRO_KEY_D:
		case ALLEGRO_KEY_RIGHT:
			keys->keyRight = true;
			break;
		case ALLEGRO_KEY_W:
		case ALLEGRO_KEY_UP:
			keys->keyUp = true;
			break;
		case ALLEGRO_KEY_S:
		case ALLEGRO_KEY_DOWN:
			keys->keyDown = true;
			break;
		case ALLEGRO_KEY_M:
			printf("Entrou no Menu: \n");
			break;
		}
	}
	else if(ev->type == ALLEGRO_EVENT_KEY_UP)
	{
		ValidaMovimento_CK_UP(player);
		switch(ev->keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
		case ALLEGRO_KEY_LEFT:
			keys->keyLeft = false;
			break;
		case ALLEGRO_KEY_D:
		case ALLEGRO_KEY_RIGHT:
			keys->keyRight = false;
			break;
		case ALLEGRO_KEY_W:
		case ALLEGRO_KEY_UP:
			keys->keyUp = false;
			break;
		case ALLEGRO_KEY_S:
		case ALLEGRO_KEY_DOWN:
			keys->keyDown = false;
			break;
		}
	}
}

void movePlayer(Keys *keys, Player *player){
	if((keys->keyUp == true && keys->keyLeft == true) ||
		(keys->keyUp == true && keys->keyRight == true) ||
		(keys->keyDown == true && keys->keyLeft == true) ||
		(keys->keyDown == true && keys->keyRight == true) ||
		(keys->keyDown == true && keys->keyUp == true))
	{
		ValidaMovimento_CK_UP(player);
		return;
	}
	if(keys->keyUp == true){
		player->state.y -= player->state.speed;
		ProcessaMovimentoCima(player);
		moveCima(player);
	}
	if(keys->keyDown == true){
		player->state.y += player->state.speed;
		ProcessaMovimentoBaixo(player);
		moveBaixo(player);
	}
	if(keys->keyLeft == true){
		player->state.x -= player->state.speed;
		ProcessaMovimentoEsquerda(player);
		moveEsquerda(player);
	}
	if(keys->keyRight == true){
		player->state.x += player->state.speed;
		ProcessaMovimentoDireita(player);
		moveDireita(player);
	}
	//al_play_sample(player->footstep, 1.0, 0.0,1.3,ALLEGRO_PLAYMODE_ONCE,NULL);
}