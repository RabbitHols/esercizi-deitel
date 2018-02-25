/*

Utilizzate una matrice per risolvere il seguente problema. Un azienda ha quattro venditori (numerati da 1 a 4)
che vendono cinque differenti prodotti numeri da (1 a 5). Una volta al giorno, ognungo dei venditori forsnisce 
un tagliando per ogni tipo di prodotto venduto. Ogni talgiando continuete:
	
	1) Il numero del venditore
	2) Il numero del prodotto
	3) Il valore totale, espresso in dollari, del venduto giornaliero di quel prodotto

Di conseguenza, ogni venditore fornisce tra 0 e 5 tagliandi al giorno. Supponete che siano disponibili i dati
dei tagliandi dell'ultimo mese. Scrivete un programma che legga le sudette informazioni, riguardanti il venduto
dell'ultimo mese, visualizzate i risultati in formato tabulare in modo che le colonne rappresentino i vari 
venditori e le righe rappresentino i singoli prodotti. Sommate ogni riga, in modo da ottenere le vendite totali
dell'ultimo mese per ognunno dei prodotti; sommate ogni colonna in modo da ottenere il totale delle vendite dell'ultimo 
mese per ognuno dei venditori. La vostra stampa tabulare dovrà includere i sudetti totali a destra delle righe e 
in fondo alle colonne

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRODOTTO 5
#define VENDITORE 4

void p_Matrx(int matrice[][PRODOTTO], int vend, int prod);

int main(int argc, char const *argv[]){
	
	srand(time(NULL));

	int matrice[VENDITORE][PRODOTTO] = {
										 {0,0,0,0,0},
										 {0,0,0,0,0},
										 {0,0,0,0,0},
										 {0,0,0,0,0}
									   };


	for(int colonne = 0; colonne < VENDITORE; colonne++){
		for(int righe = 0; righe < PRODOTTO; righe++){
			matrice[colonne][righe] = rand() % 10;
		}
	}

	p_Matrx(matrice, VENDITORE, PRODOTTO);

	puts("\n");
// 	Tot vendite prodotti singoli
	
	int P_singoli[5] = {0};

	int cnt = 0;

	for(int vnd = 0; vnd < PRODOTTO; vnd++){
		for(cnt = 0; cnt < VENDITORE; cnt++){
			P_singoli[vnd] = matrice[cnt][vnd] + P_singoli[vnd];
		}
			printf("TOT VENDITE PRDOTTI SINGOLI  %d = %d\n", vnd, P_singoli[vnd]);
	}

	puts("\n");

	// 	Tot vendite venditori singoli
	
	int V_singoli[5] = {0};

	cnt = 0;

	for(int vnd = 0; vnd < VENDITORE; vnd++){
		for(cnt = 0; cnt < PRODOTTO; cnt++){
			V_singoli[vnd] = matrice[vnd][cnt] + V_singoli[vnd];
		}
			printf("TOT VENDITE VENDITORI SINGOLI %d = %d\n", vnd, V_singoli[vnd]);
	}

	return 0;
}

void p_Matrx(int matrice[][PRODOTTO], int vend, int prod){

	for(int colonne = 0; colonne < vend; colonne++){
		for(int righe = 0; righe < prod; righe++){
			printf("%2d\t", matrice[colonne][righe]);
		}
		puts("");
	}

}