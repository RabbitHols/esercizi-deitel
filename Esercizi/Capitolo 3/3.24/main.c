/*S
i prenda in input una serie di 10 numeri e in seguito si determini e visualizzi
il maggiore di essi

Il programma deve utilizzare 3 variabili

counter: un contatore per contare fino a 10 per tenere traccia dei numero di numeri immessi
number : il numero corrente immesso nel programma
largest: il numero più grande trovato fino a questo punto
*/

#include <stdio.h>

int main(){

	int contatore;
	int nrCorrente;
	int nrMax;


	nrMax = 0;

	for(contatore = 0; contatore < 10; contatore++){
		printf("Quante vendite hai effettuato? ");
		scanf("%d", &nrCorrente);

		nrMax = (nrCorrente > nrMax) ? nrCorrente : nrMax;

		printf("nr corrente: \t\t%d \n", nrCorrente);
		printf("nr max fino ad ora: \t%d\n", nrMax);
	}


	printf("Il max è \t%d\n", nrMax);

	return 0;
}