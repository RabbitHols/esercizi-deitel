/**
Scrivere un programma che trovi il minore di diversi interi. Supponete che il primo 
valore letto specifichi il numero di iterazioni da fare
**/

#include <stdio.h>


int main(){
	
	int iterazioni;
	int cnt;
	int num;
	int min;

	printf("Dammi numero di iterazioni da svolgere\n");
	scanf("%d", &iterazioni);

	printf("Dammi numero\n");
	scanf("%d", &num);

	min = num;

	for(cnt = 0; cnt < iterazioni - 1; cnt++){
		printf("Dammi numero\n");
		scanf("%d", &num);

		min = (num < min) ? num : min;

	}

	printf("Il minore e': %d\n", min);	

	return 0;
}
