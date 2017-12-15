/*
Scrivere un programma che visualizzi una tabella di questo genere

N		10*N		100*N		1000*N

1		10			100			10000
2		20			200			20000


fino ad 10
*/

#include <stdio.h>

int main(){


	printf("\tN\t10*N\t100*N\t1000*N\n\n");

	int contatore;

	for(contatore = 1; contatore <= 10; contatore++){

		printf("\t%.0d\t%.0d\t%.0d\t%.0d\n", contatore, contatore*10, contatore*100, contatore*1000);

	}	

	return 0;
}