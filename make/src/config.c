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

void libera_config(config *l, type) {
    elemento *e, *temp;

    e = l->inicio;
    while (e != NULL) {
        temp = e->proximo;
        libera_string(e->string);
        libera_string(e->var);

        free(e);
        e = temp;
    }
    free(l);
    if(type == CONFIG) {
        loaded_config = 0;
    }
    else if(type == IDIOMA) {
        loaded_idioma = 0;
    }
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
        return "failed";
    }
    else if (strcmp(var, anterior->var) == 0) {
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
    }
    else if (strcmp(var, anterior->var) == 0) {
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
    int i;
    for (i = 0; i < strlen(string); i++) {
        free(&string[i]);
    }
}

int conta_linhas(FILE *entrada) {
    int lines;
    char caracter;
    lines = 1;

    while ((caracter = fgetc(entrada)) != EOF) {
        if (caracter == '\n')
            lines++;
    }
    //Retorna o ponteiro para inicio do arquivo.
    rewind(entrada);
    return lines;
}

int conta_until(FILE *entrada, char until) {
    int count;
    char caracter;

    for (count = 0; (caracter = fgetc(entrada)) != until && caracter != EOF; count++);
    //melhorar essa parte
    if (until == '\n' && caracter != EOF) {
        return --count;
    }
    return count;
}

bool load_config(char *config_file, int type) {
    char **var, **string;
    FILE *entrada;
    int i, linhas, count, before;
    int *tstring, *tvar;
    char c;

    switch (type) {
        case CONFIG:
            aloca(&arquivo_configuracao);
            break;
        case IDIOMA:
            aloca(&arquivo_idioma);
            break;
        default:
            fprintf(stderr, "Tipo incorreto de configuração\n");
            return false;
    }

    entrada = fopen(config_file, "r");

    if (!entrada) {
        fprintf(stderr, "erro na leitura do arquivo de configuração.\n");
        return false;
    }

    linhas = conta_linhas(entrada);
    var = malloc(linhas * sizeof (char));
    string = malloc(linhas * sizeof (char));
    tvar = malloc(linhas * sizeof (int));
    tstring = malloc(linhas * sizeof (int));

    for (i = 0; i < linhas; i++) {
        tvar[i] = conta_until(entrada, '=');
        tstring[i] = conta_until(entrada, '\n');

        var[i] = malloc(tvar[i] * sizeof (char));
        string[i] = malloc(tstring[i] * sizeof (char));
    }
    rewind(entrada);

    for (i = 0; i < linhas; i++) {
        fgets(var[i], tvar[i] + 1, entrada);
        fgetc(entrada);
        fgets(string[i], tstring[i] + 1, entrada);
        do {
            fscanf(entrada, "%c", &c);
        } while (c != '\n');

        switch (type) {
            case CONFIG:
                insere_config(&arquivo_configuracao, var[i], string[i]);
                break;
            case IDIOMA:
                insere_config(&arquivo_idioma, var[i], string[i]);
                break;
        }
    }
    fclose(entrada);

    switch (type) {
        case CONFIG:
            loaded_config = 1;
            break;
        case IDIOMA:
            loaded_idioma = 1;
            break;
    }

    return true;
}


//Utilizar no projeto as funções abaixo.

bool load_configuracao(char *config_file) {
    return load_config(config_file, CONFIG);
    if(loaded_config == 1) {
        return false;
    }
}

bool load_idioma(char *config_file) {
    if(loaded_idioma == 1) {
        return false;
    }
    return load_config(config_file, IDIOMA);
}

char *get_configuracao(char *var) {
    if (loaded_config == 1) {
        return retorna_config(&arquivo_configuracao, var);
    }
}

char *get_idioma(char *var) {
    if (loaded_idioma == 1) {
        return retorna_config(&arquivo_idioma, var);
    }
}

void limpa_config() {
    libera_config(&arquivo_configuracao, CONFIG);
}

void limpa_idioma() {
    libera_config(&arquivo_idioma, IDIOMA);
}

void apaga_idioma(char *var){
    apaga_config(&arquivo_idioma, char *var);
}

void apaga_configuracao(char *var){
    apaga_config(&arquivo_configuracao, char *var);
}

void imprime_idioma(){
    imprime_config(&arquivo_idioma);
}

void imprime_configuracao(){
    imprime_config(&arquivo_configuracao);
}