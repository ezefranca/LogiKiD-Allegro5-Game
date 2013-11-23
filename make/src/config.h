/*
 * Contem as configurações do sistema
 * Inicio: 13/10/2013
 * Autor: Gabriel Fontenelle Senno Silva
 */

#ifndef CONFIG_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "comum.h"

#define CONFIG_H
#define CONFIG 0
#define IDIOMA 1


typedef struct _elemento {
  char *string;
  char *var;
  struct _elemento *proximo;
} elemento;

typedef struct {
  elemento *inicio;
} config;

void imprime_config(config *l);

bool load_configuracao(char *config_file);

bool load_idioma(char *config_file);

char *get_configuracao(char *var);

char *get_idioma(char *var);

void limpa_config();

void limpa_idioma();

void apaga_configuracao(char *var);

void apaga_idioma(char *var);

void imprime_idioma();

void imprime_configuracao();

#endif
