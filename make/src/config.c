#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "config.h"

config arquivo_configuracao;
config arquivo_idioma;
int loaded_config = 0;
int loaded_idioma = 0;

config *aloca() {
    config *l = malloc(sizeof (config));
    l->inicio = NULL;
    return l;
}

void libera_config(config *l) {
    elemento *e, *temp;

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

bool load_config(char *config_file, int type){
    char **var, **string;
    FILE *entrada;
    int i, linhas;
    
    switch(type){
        case CONFIG:
            aloca(&arquivo_configuracao);
            break;
        case IDIOMA:
            aloca(&arquivo_idioma);
            break;
        default:
            fprintf(stderr, "Tipo incorreto de configuração\n");
            exit(EXIT_FAILURE);
    }

    entrada = fopen(config_file. "r");
    
    if(!entrada) {
	fprint(stderr, "erro na leitura do arquivo de configuração.\n");
        return false;
    }

    linhas = conta_linhas(entrada);
    var = malloc(linhas * sizeof(char));
    for(i = 0; i < linhas; i++) {
        var[i] = malloc(conta_until(&entrada, '=') * sizeof(char));
        string[i] = malloc(conta_until(&entrada, '\n') * sizeof(char));
    }
    rewind(entrada);
    
    for(i = 0; i < linhas; i++) {
        fgets(var[i], sizeof(var[i]), entrada);
        //Consome o sinal de igual.
        getc(entrada);
        fgets(string[i], sizeof(string[i]), entrada);
        switch(type){
            case CONFIG:
                insere_config(&arquivo_configuracao, var[i], string[i]);
                break;
            case IDIOMA:
                insere_config(&arquivo_idioma, var[i], string[i]);
                break;
        }
    }
    
    switch(type){
        case CONFIG:
            loaded_config = 1;
            break;
        case IDIOMA:
            loaded_idioma = 1;
            break;
    }
    
    return true;
}

int conta_linhas(FILE *entrada) {
    int caracter, lines;
    lines = 0;
    
    while (EOF !=(caracter=fgetc(entrada))) {
        if (caracter=='\n')
           lines++;
    }
    //Retorna o ponteiro para inicio do arquivo.
    rewind(entrada);
    return lines;
}

int conta_until(FILE *entrada, char until){
    int count;
    
    for(count=0; getc(entrada) != until;count++);
    return count;
}


//Utilizar no projeto as funções abaixo.

bool load_configuracao(char *config_file) {
    return load_config(config_file, CONFIG);
}

bool load_idioma(char *config_file) {
    return load_config(config_file, IDIOMA);
}

char *get_configuracao(char *var) {
    if(loaded_config == 1) {
        return retorna_config(arquivo_configuracao, var);
    }
}

char *get_idioma(char *var) {
    if(loaded_idioma == 1) {
        return retorna_config(arquivo_idioma, var);
    }
}

void limpa_config(){
    libera_config(&arquivo_configuracao);
}

void limpa_idioma(){
    libera_config(&arquivo_idioma);
}