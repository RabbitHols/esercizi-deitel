/*
Scrivere un programma che utilizzi un ciclo per riprodurre la seguente tabella valori:

A	A+2		A+4		A+6

3	5		7		9

per 5 volte

*/

#include <stdio.h>

int main(){

	printf("\tA\tA+2\tA+4\tA+6\n\n");

	int contatore;
	int numero		= 3;
	for(contatore = 0; contatore < 4; contatore++){
		printf("\t%d\t%d\t%d\t%d\n", numero, numero+2,numero+4, numero+9);
		numero += 3;
	}


	return 0;
}