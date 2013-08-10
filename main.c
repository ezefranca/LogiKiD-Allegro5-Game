#include <allegro5/allegro.h>

// Nossa conhecida função main...
int main(void)
{
    // Variável representando a janela principal
    ALLEGRO_DISPLAY *janela = NULL;

    // Inicializamos a biblioteca
    al_init();

    // Criamos a nossa janela - dimensões de 640x480 px
    janela = al_create_display(640, 480);

    // Preenchemos a janela de branco
    al_clear_to_color(al_map_rgb(255, 255, 255));

    // Atualiza a tela
    al_flip_display();

    // Segura a execução por 10 segundos
    al_rest(10.0);

    // Finaliza a janela
    al_destroy_display(janela);

    return 0;
}
