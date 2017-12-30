/**
Scrivere un programma che sommi una sequenza di interi. Supponete che il
primo intero letto con la scanf specifichi il numero dei valori che dovranno essere immessi. Il vostor programma dovrà leggere solo un valori per ogni
volta che la scanf sarà eseguita. Una tipica sequenza di input potrebbe essere:

5 100 200 300 400 500
**/

#include <stdio.h>

int main(){
		
	int cnt; 
	int num;

	printf("Iniziamo la sequenza dammi nr iterazioni\n");
	scanf("%d", &cnt);

	for(int c = 0; c < cnt; c++){
		printf("Dammi input\n");
		scanf("%d", &num);
	}


	return 0;
}
