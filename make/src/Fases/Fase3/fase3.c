#include "../../comum.h"
#include "fase3.h"
#include "../../Player.h"


void logicLevelTres(bool *gateOne, bool *gateTwo, bool *gateThree, bool *gateFour, Player *player)
{
	if((player->state.x > 0 && player->state.x < 20) && (player->state.y > 40 && player->state.y < 70))
	{
		if(*gateOne == false){
			*gateOne = true;
			printf("False para true\n");
		}
		else{
			*gateOne = false;
			printf("True para false\n");
		}
	}
	if ((player->state.y > 100 && player->state.y < 120) && (player->state.x > 0 && player->state.x < 20))
	{
		if(*gateTwo == false){
			*gateTwo = true;
			printf("False para true\n");
		}
		else{
			*gateTwo = false;
			printf("True para false\n");
		}
	}
	if ((player->state.y > 200 && player->state.y < 220) && (player->state.x > 0 && player->state.x < 20))
	{
		if(*gateThree == false){
			*gateThree = true;
			printf("False para true\n");
		}
		else{
			*gateThree = false;
			printf("True para false\n");
		}
	}
	if ((player->state.y > 260 && player->state.y < 280) && (player->state.x > 0 && player->state.x < 20))
	{
		if(*gateFour == false){
			*gateFour = true;
			printf("False para true\n");
		}
		else{
			*gateFour = false;
			printf("True para false\n");
		}
	}
}

void drawLogicLevelTres(bool gateOne, bool gateTwo, bool gateThree, bool gateFour, bool *complete, LevelTres *levelTres){

	al_draw_bitmap(levelTres->portas, 0, 0 , 0);
	if(gateOne)  levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-1XXX.png");
	if(gateTwo)  levelTres->circ2 = al_load_bitmap("./data/levels/fase3/DES1-X1XX.png");
	if(!gateOne)  levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-0XXX.png");
	if(!gateTwo)  levelTres->circ2 = al_load_bitmap("./data/levels/fase3/DES1-X0XX.png");

	if(!gateOne && !gateTwo) levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-00XX.png");
	if(!gateOne && gateTwo) levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-01XX.png");
	if(gateOne && !gateTwo) levelTres->circ1= al_load_bitmap("./data/levels/fase3/DES1-10XX.png");
	if(gateOne && gateTwo)  levelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-11XX.png");

	if(gateThree)  levelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-XX1X.png");
	if(gateFour)  levelTres->circ4 = al_load_bitmap("./data/levels/fase3/DES1-XXX1.png");
	if(!gateThree)  levelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-XX0X.png");
	if(!gateFour)  levelTres->circ4 = al_load_bitmap("./data/levels/fase3/DES1-XXX0.png");

	if(!gateThree && !gateFour) levelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-XX00.png");
	if(!gateThree && gateFour) levelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-XX01.png");
	if(gateThree && !gateFour) levelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-XX10.png");
	if(gateThree && gateFour)  levelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-XX11.png");


	if(!gateOne && gateTwo && (!gateThree || !gateFour))
	{
		levelTres->circ5 = al_load_bitmap("./data/levels/fase3/DES1-UM.png");
		*complete = true;
	}
	else levelTres->circ5 = al_load_bitmap("./data/levels/fase3/DES1-ZERO.png");

    levelTres->chances++;

}

void initDrawGatesLevelTres(LevelTres *LevelTres){

	int i = 0;
	LevelTres->isOn[i] = true;
	for(i = 1; i < 5; i++){
		LevelTres->isOn[i] = false;
	}
	LevelTres->portas = al_load_bitmap("./data/levels/fase3/DES1-portas.png");
	LevelTres->circ1 = al_load_bitmap("./data/levels/fase3/DES1-1000.png");
	LevelTres->circ2 = al_load_bitmap("./data/levels/fase3/DES1-X0XX.png");
	LevelTres->circ3 = al_load_bitmap("./data/levels/fase3/DES1-XX0X.png");
	LevelTres->circ4 = al_load_bitmap("./data/levels/fase3/DES1-XXX0.png");
	LevelTres->circ5 = al_load_bitmap("./data/levels/fase3/DES1-ZERO.png");
	LevelTres->chances = 0;
	printf("iniciou com %d chances\n", LevelTres->chances);
}
void drawLevelTres(LevelTres *LevelTres){
	al_draw_bitmap(LevelTres->circ4, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ3, 0, 0 , 0);
       al_draw_bitmap(LevelTres->circ2, 0, 0 , 0);
	al_draw_bitmap(LevelTres->circ1, 0, 0 , 0);

	al_draw_bitmap(LevelTres->circ5, 0, 0 , 0);
	al_draw_bitmap(LevelTres->portas, 0, 0 , 0);
}

void destroyLevelTres(LevelTres *LevelTres){
	al_destroy_bitmap(LevelTres->circ1);
	al_destroy_bitmap(LevelTres->circ2);
	al_destroy_bitmap(LevelTres->circ3);
	al_destroy_bitmap(LevelTres->circ4);
	al_destroy_bitmap(LevelTres->circ5);
	al_destroy_bitmap(LevelTres->portas);
}