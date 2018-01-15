
/**

Scrivere un programma che prenda in input un anno compreso nell'intervallo dal
1994 al 1999 e utilizzi un iterazione con un ciclo for per produrre un calendario
compendiato, visualizzato in modo ordinato. Attenti agli anni bisestili

**/

#include <stdio.h>

int main(){

	int anno;
	char mesi[][12] = {"GENNAIO", "FEBBRAIO", "MARZO", "APRILE", "MAGGIO", "GIUGNO", "LUGLIO",
				  "AGOSTO", "SETTEBRE", "OTTOBRE", "NOVEMBRE", "DICEMBRE"};

	int giorni[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	printf("### L'anno deve essere compreso tra 1994 - 1999 ### \n");

		printf("Che hanno vuoi visualizzare ?\n");
		// scanf("%d", &anno);
	

	for(int cnt = 0; cnt < 12; cnt++){
		printf("%s \n", mesi[cnt]);
		for(int t = 1; t <= giorni[cnt]; t++){
			if(t % 5 == 0){printf("\n");};
			printf("%d\t\t", t);
		}
		printf("\n\n");
	}




	return 0;
}
