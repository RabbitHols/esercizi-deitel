/**
Scrivere un programma che legga 5 numeri
ognuno compreso tra 1 e 30.Per ogni numero letto,
il vostro programma dovrà visualizzare una riga 
contente quel numero di asterischi adiacenti.

Ex: 5 *****

**/

#include <stdio.h>

int main(){

	int num = 0;

	printf("### REGOLA ###\n");
	printf("DAMMI 5 NUMERI OGNUNGO COMPRESO TRA 1 E 30\n");

	int cnt;
	for(cnt = 1; cnt <= 5; cnt++){
		printf("Dammi il %d/o numero", cnt);
		scanf("%d", &num);

		if(num > 0 && num <= 30){
			for(int xcnt = 0; xcnt < num; xcnt++){
			printf("*");
		}
			printf("\n");
		} else {
			printf("Ricordati di rispettare il range\n");
		}
		
	}


	return 0;
}