/*
Scrivere un programma che utilizzi un ciclo per visualizzare i numeri da 1 a 10
a fianco sulla stessa riga e con tre spazi tra ognuno di essi
*/

#include <stdio.h>

int main(){

	int contatore = 1;

	for(contatore; contatore <= 10; contatore++){
		printf("%3d", contatore);
	}

	printf("\n");

	return 0;
}