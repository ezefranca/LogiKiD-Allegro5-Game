#include "comum.h"

void QuitGame()
{
	al_destroy_event_queue(game.fila_eventos);
	al_destroy_display(game.janela);
}

int main(void)
{
	if (!inicializar())
			return -1;

	GameLoop();

	QuitGame();
	return 0;
}
