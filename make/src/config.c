#include "config.h"
#include "comum.h"

config arquivo_configuracao;
config arquivo_idioma;
config arquivo_config_user;

int loaded_config = 0;
int loaded_idioma = 0;
int loaded_config_user = 0;

void libera_string(char *string) {
    int i;
    for (i = 0; i < strlen(string); i++) {
        free(&string[i]);
    }
}

config *aloca() {
    config *l = malloc(sizeof (config));
    l->inicio = NULL;
    return l;
}

void libera_config(config *l, int type) {
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
    switch (type) {
        case CONFIG:
            loaded_config = 0;
            break;
        case IDIOMA:
            loaded_idioma = 0;
            break;
        case CONFIG_USER:
            loaded_config_user = 0;
            break;
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
        return var;
    } else if (strcmp(var, anterior->var) == 0) {
        //l->inicio = anterior->proximo;
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
        return var;
    }
}

void apaga_config(config *l, char *var) {
    elemento *anterior, *atual;
    anterior = l->inicio;
    if (anterior == NULL) {
        fprintf(stderr, "list already empty\n");
    } else if (strcmp(var, anterior->var) == 0) {
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

void imprime_config(config *l, FILE *file) {
    elemento *e;
    for (e = l->inicio; e != NULL; e = e->proximo)
        fprintf(file, "%s=%s\n", e->var, e->string);
}

int conta_linhas(FILE *entrada) {
    int lines;
    char caracter, last_caracter;
    lines = 1;

    while ((caracter = fgetc(entrada)) != EOF) {
        if (caracter == '\n' || caracter == '\0')
            lines++;
        last_caracter = caracter;
    }
    if (last_caracter == '\n' || caracter == '\0') --lines;

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
    int i, linhas;
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
            case CONFIG_USER:
                insere_config(&arquivo_config_user, var[i], string[i]);
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
        case CONFIG_USER:
            loaded_config_user = 1;
            break;
    }

    return true;
}


//Utilizar no projeto as funções abaixo.

bool load_configuracao(char *config_file) {
    if (loaded_config == 1) {
        return true;
    }
    return load_config(config_file, CONFIG);
}

bool load_idioma(char *config_file) {
    if (loaded_idioma == 1) {
        return true;
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

void apaga_idioma(char *var) {
    apaga_config(&arquivo_idioma, var);
}

void apaga_configuracao(char *var) {
    apaga_config(&arquivo_configuracao, var);
}

void imprime_idioma() {
    imprime_config(&arquivo_idioma, stdout);
}

void imprime_configuracao() {
    imprime_config(&arquivo_configuracao, stdout);
}

char *get_config_user(char *var) {
    if (loaded_config_user == 1) {
        return retorna_config(&arquivo_config_user, var);
    }
}

void imprime_config_user() {
    imprime_config(&arquivo_config_user, stdout);
}

void apaga_config_user(char *var) {
    apaga_config(&arquivo_config_user, var);
}

void adiciona_config_user(char *string, char *var) {
    insere_config(&arquivo_config_user, var, string);
}

void update_config_user(char *string, char *var) {
    apaga_config(&arquivo_config_user, var);
    adiciona_config_user(*string, *var);
}

void limpa_config_user() {
    libera_config(&arquivo_config_user, CONFIG_USER);
}

bool create_config_user(char *config_file) {
    //Configuracoes padrao para o usuario
    FILE *entrada;

    entrada = fopen(config_file, "ab+");
    if (!entrada)
        return false;
    fclose(entrada);

    aloca(&arquivo_config_user);
    //Adicionar as configuracoes padroes em:

    //adiciona_config_user(string, var);
    //adiciona_config_user(string, var);
    //adiciona_config_user(string, var);
    //adiciona_config_user(string, var);
    //adiciona_config_user(string, var);

    if (arquivo_config_user->inicio != NULL) {
        loaded_config_user = 1;
        return true;
    }
    return false;
}

bool load_config_user(char *config_file) {
    if (loaded_config_user == 1) {
        return true;
    }
    if (load_config(config_file, CONFIG_USER)) {
        return true;
    }
    return create_config_user(config_file);
}

bool salva_config_user(char *config_file) {
    FILE *entrada;

    if (loadead_config_user == 1) {
        entrada = fopen(config_file, "w");
        if (!entrada)
            return false;

        imprime_config(&arquivo_config_user, entrada);

        fclose(entrada);
        return true;
    } else {
        return false;
    }
}

