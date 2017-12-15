/**

Scrivere un programma che prenda in input dalla tastiera tre diversi interi e quindi visualizzi la somma,
la media, il prodotto, il minore e il maggiore di questi numeri. Usate soltando la forma a selezione singola
della istruzione if che avete appreso in questo capitolo.

**/

#include <stdio.h>

void somma(int a, int b, int c){
	int somma = a + b + c;
	printf("SOMMA = %d\n",somma);
}

void media(int a, int b, int c){
	double media = ((double)a + (double)b + (double)c) / 3;
	printf("MEDIA = %.2f\n", media);
}

void prodotto(int a, int b, int c){
	int prodotto = a * b * c;
	printf("PRODOTTO = %d\n", prodotto);
}

void minore(int a, int b, int c){
	
	int minore = a;

	minore = (minore < b) ? minore : b;
	minore = (minore < c) ? minore : c;

	printf("MINORE = %d\n", minore);
}

void maggiore(int a, int b, int c){
	
	int maggiore = a;

	maggiore = (maggiore > b) ? maggiore : b;
	maggiore = (maggiore > c) ? maggiore : c;

	printf("MAGGIORE = %d\n", maggiore);
}


int main(int argc, char const *argv[])
{
	
	int a = 1; int b = 12; int c = 2;

	somma(a,b,c);
	media(a,b,c);
	prodotto(a,b,c);
	minore(a,b,c);
	maggiore(a,b,c);

	return 0;
}