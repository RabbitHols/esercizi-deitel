/*
 * Avvia un ciclo di 3.000.000 di iterazione
 * ad ogni multiplo di 1.000.000 stampare il numero
 */


#include <stdio.h>

int main(){
	
	int cont = 0;

	while(cont <= 3000000){
		(cont % 1000000 != 0) ?: printf("%d\n", cont);
	cont++;	
	}	


	return 0;
}
