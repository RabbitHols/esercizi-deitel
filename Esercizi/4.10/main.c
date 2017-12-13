/**
* Scrivere un programma che calcoli e visualizzi la media di diversi
* interi. Supponete che l'ultimo valore letto con la scanf sia quello
* della sentinella 9999. Una tipica sequenza di input potrebbe essere:
* 10 8 11 7 9 9999
**/

#include <stdio.h>

int main()
{
	float sentinella	= 9999;
	float check 		= 0;	
	float tot			= 0;
	float media			= 0;

	int cont			= 0;

	while(check != sentinella){
		
		tot		= tot + check;
		media	= tot / cont;


		printf("DAMMI NUMERO\n");
		scanf("%f", &check);

		if(check == sentinella){
			continue;
		}

		cont++;

		}

		printf("La media e' di: %f\n", media);

	return 0;
}
