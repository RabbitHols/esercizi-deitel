/*
Trovare i due numeri maggiori tra 10 valori.Potete prendere in input ogni valore
soltanto una volta
*/

#include <stdio.h>

int main(){

	int nr;
	int max		= 0;
	int smax	= 0;

	int contatore;

	for(contatore = 0; contatore < 10; contatore++){
		printf("Dammi numero\n");
		scanf("%d", &nr);

		if(nr > max){
			smax = max;
			max = nr;
		}

	}


	printf("Max = %d\n", max);
	printf("Smax = %d\n", smax);

	return 0;
}