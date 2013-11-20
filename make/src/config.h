/*
 * Contem as configurações do sistema
 * Inicio: 13/10/2013
 * Autor: Gabriel Fontenelle Senno Silva
 */
 
#ifndef CONFIG_H
#define CONFIG_H

typedef struct _elemento {
  char *string;
  char *var;
  struct _elemento *proximo;
} elemento;

typedef struct {
  elemento *inicio;
} config;

config *aloca();

void libera_config(config *l);

void insere_config(config *l, char *var, char *string);

char *retorna_config(config *l, char *var);

void apaga_config(lista *l, char *var);

void imprime_config(lista *l);


#endif