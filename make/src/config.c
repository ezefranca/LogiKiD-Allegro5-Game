#include <stdlib.h>
#include <string.h>
#include "config.h"

struct Config load_config(char *arquivo) {


}

struct Config load_idioma(char *idioma){
	char *local_idioma;
	int loaded;
	
	strcpy(local_idioma, "local aqui");
	strcat(local_idioma, idioma);
	strcat(local_idioma, ".conf");
	
	
	
	loaded = 1;
	while(loaded) {
		
		strcpy(local_idioma, "local aqui");
		strcat(local_idioma, idioma);
		strcat(local_idioma, ".conf");
	
		//Abre idioma
		FILE *arquivo = fopen(local_idioma, "r");
	
		if(file) {
			
			
			
			loaded = 0;
		}
		else {
			printf("Arquivo de idioma não localizado\n");
			printf("Will try to load the default language\n");
			
		}
	}
}