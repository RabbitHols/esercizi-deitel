/**

Scrivere delle istruzioni che visualizzino le seguenti sequenze di valori:

a) 1,2,3,4,5,6,7
b) 3,8,13,18,23
c) 20,14,8,2,-4,-10
d) 19,27,35,43,51

**/

#include  <stdio.h>

int main()
{

// RIGA A
	
	printf("a) ");

	int cont = 0;

	for(cont = 0; cont < 8; cont++){
		printf("%d ", cont);
	}

	printf("\n");

// RIGA B

	int numero = 3;

	printf("b) ");

	for(cont = 0; cont < 5; cont++){
		printf("%d ", numero);

		numero += 5;
	}

	printf("\n");

// RIGA C

	printf("c) ");

	numero = 20; // riutilizzo numero

	for(cont = 0; cont < 6; cont++){
		printf("%d ", numero);

		numero -= 4;
	}

	printf("\n");

// RIGA D

	printf("c) ");

	numero = 19;

	for(cont = 0; cont < 5; cont++){
		printf("%d ", numero);

		numero += 8;
	}

	printf("\n");

	return 0;
}