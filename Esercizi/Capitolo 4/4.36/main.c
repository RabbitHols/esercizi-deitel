
/**

Scrivere un programma che prenda in input un anno compreso nell'intervallo dal
1994 al 1999 e utilizzi un iterazione con un ciclo for per produrre un calendario
compendiato, visualizzato in modo ordinato. Attenti agli anni bisestili

**/

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

int main(int argc, char const *argv[]){
	if(argv[1] == NULL){
		return 0;
	}

	int anno = atoi(argv[1]);

	char mesi[][12] = {"GENNAIO", "FEBBRAIO", "MARZO", "APRILE", "MAGGIO", "GIUGNO", "LUGLIO",
				  "AGOSTO", "SETTEBRE", "OTTOBRE", "NOVEMBRE", "DICEMBRE"};

	int giorni[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if(anno == 1992 || anno == 1996){
		giorni[1] = giorni[1] + 1;
	}


	for(int cnt = 0; cnt < 12; cnt++){
		printf("%s \n", mesi[cnt]);
		for(int t = 1; t <= giorni[cnt]; t++){
			printf("%d\t\t", t);
			if(t % 7 == 0){
				printf("\n");
			}	
		}
		printf("\n\n");
	}




	return 0;
}
