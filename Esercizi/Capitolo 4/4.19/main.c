/**
Un azienda di vendita per corrispondenza vende 5 differenti
prodotti i cui prezzi al dettaglio sono mostrati qui sotto:

NUM PRODOTTO 	PREZZO AL DETTAGLIO
1				2,98
2				4,50
3				9,98
4				4,49
5				6,87

Scrivere un programma che legga una serie di coppie 
di numeri come segue:

1)Numero prodotto
2)Quantità venduta in un giorno

Il vostro programma dovrà utilizzare una istruzione
di switch per aiutare a determinare il prezzo al
dettaglio di ogni prodotto. Il vostro programma dovrà
calcolare e visualizzare il valore totale al dettaglio
di tutti i prodotti venduti nell'ultima settimana.

**/

#include <stdio.h>

int main(){

	int N_prodotto;
	int Q_prodotto;
	float P_prezzo;
	float tot;

	printf("Dammi il numero del proddoto\n");
	scanf("%d", &N_prodotto);

	printf("Dammi la quantità di prodotto venduto nelle ultime 24h\n");
	scanf("%d", &Q_prodotto);



		switch(N_prodotto){
		case 1:
			P_prezzo = 2.98;
			tot = (float) (P_prezzo * Q_prodotto);
			printf("%f\n", tot);
			break;

		case 2:
			P_prezzo = 4.50;
			tot = (float) (P_prezzo * Q_prodotto);
			printf("%f\n", tot);
			break;

		case 3:
			P_prezzo = 9.98;
			tot = (float) (P_prezzo * Q_prodotto);
			printf("%f\n", tot);
			break;

		case 4: 
			P_prezzo = 4.49;
			tot = (float) (P_prezzo * Q_prodotto);
			printf("%f\n", tot);
			break;

		case 5:
			P_prezzo = 6.87;
			tot = (float) (P_prezzo * Q_prodotto);
			printf("%f\n", tot);
			break;

		default:
			printf("Spiacente prodotto non disponibile\n");
	}


	return 0;
}