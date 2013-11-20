#include <stdlib.h>
#include <string.h>
#include "config.h"

config arquivo_configuracao;
int loaded = 0;

config *aloca() {
    config *l = malloc(sizeof (config));
    l->inicio = NULL;
    return l;
}

void libera_config(config *l) {
    elemento *e, *temp;
    int i;

    e = l->comeco;
    while (e != NULL) {
        temp = e->proximo;
        libera_string(e->string);
        libera_string(e->var);

        free(e);
        e = temp;
    }
    free(l);
}

void insere_config(config *l, char *var, char *string) {
    elemento *e = malloc(sizeof (elemento));
    e->var = var;
    e->string = string;
    if (l->inicio == NULL) {
        l->inicio = e;
        e->proximo = NULL;
    } else {
        e->proximo = l->inicio;
        l->inicio = e;
    }
}

char *retorna_config(config *l, char *var) {
    elemento *anterior, *atual;
    anterior = l->inicio;
    if (anterior == NULL) {
        fprintf(stderr, "list empty\n");
        exit(EXIT_FAILURE);
    }
    if (strcmp(var, anterior->var) == 0) {
        l->inicio = anterior->proximo;
        return (anterior->string);
    } else {
        atual = anterior->proximo;
        while (atual != NULL && strcmp(var, atual->var) != 0) {
            anterior = atual;
            atual = anterior->proximo;
        }

        if (atual != NULL) {
            return (atual->string);
        }
    }

}

void apaga_config(config *l, char *var) {
    elemento *anterior, *atual;
    anterior = l->inicio;
    if (anterior == NULL) {
        fprintf(stderr, "list already empty\n");
        exit(EXIT_FAILURE);
    }
    if (strcmp(var, anterior->var) == 0) {
        l->inicio = anterior->proximo;
        libera_string(anterior->var);
        libera_string(anterior->string);
        free(anterior);
    } else {
        atual = anterior->proximo;
        while (atual != NULL && strcmp(var, atual->var) != 0) {
            anterior = atual;
            atual = anterior->proximo;
        }

        if (atual != NULL) {
            anterior->proximo = atual->proximo;
            libera_string(atual->var);
            libera_string(atual->string);
            free(atual);
        }
    }
}

void imprime_config(config *l) {
    elemento *e;
    for (e = l->inicio; e != NULL; e = e->proximo)
        printf("%s = %s\n", e->var, e->string);
}

void libera_string(char *string) {
    for (i = 0; i < strlen(string); i++) {
        free(string[i]);
    }
}

bool load_configuracao(config *l, char *config_file){
    FILE *entrada;
    entrada = fopen(config_file. "r");
    if(!entrada) {
	fprint(stderr, "erro na leitura do arquivo de configuração.\n");
        return false;
    }
    
    loaded = 1;
}

char *get_configuracao(char *var) {
    if(loaded == 1) {
        return retorna_config(&arquivo_configuracao, var);
    }
}