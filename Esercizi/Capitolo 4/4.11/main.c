/**
Scrivere un programma che trovi il minore di diversi interi. Supponete che il primo 
valore letto specifichi il numero di iterazioni da fare
**/

#include <stdio.h>


int main(){
	
	int iterazioni;
	int cont;
	int min;
	int numero;

	printf("Numero Iterazioni?\n");
	scanf("%d", &iterazioni);
	
	sentinella = iterazioni;

	for(cont = 0; cont < iterazioni; cont++){
		printf("Dammi numero\n");
		scanf("%d", &numero);

		if(numero > sentinella){
			min = sentinella;
		} else {
			min = numero;
		}

		sentinella = numero;
		
	}

	printf("%d\n", min)


	return 0;
}
