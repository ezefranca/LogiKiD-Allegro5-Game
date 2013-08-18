/*
 * Código main
 * Inicio: 11/08/2013
 * Autor: Alexandre Savelli Bencz
 */

#include "comum.h"
#include "lEngine/lEngine.h"

void QuitGame()
{
	al_destroy_event_queue(game.fila_eventos);
	al_destroy_display(game.janela);
	al_destroy_font(game.fonte);
}

int main(void)
{
	//inputLogic("logic/exemplo.txt");

	if (!inicializar())
			return -1;

	GameLoop();

	QuitGame();
	return 0;
}