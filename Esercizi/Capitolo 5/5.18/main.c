/*
Scrivete un programma che prenda in input una serie di interi e li passi, uno per volta, 
alla funzione even. che utilizzerà, l'operatore modulo per determinare se è pari o dispari
1 pari 0 dispari

*/

#include <stdio.h>
#include <stdlib.h>

int even(int);

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	printf("%d\n", even(n));

	return 0;
}

int even(int n){
	return (n & 1 == 1)? 0 : 1;
}