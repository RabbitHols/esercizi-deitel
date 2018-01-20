/**
Scrivete una funzione multiple che per una coppia di interi determini se il
secondo sia un multipo del primo. La funzione dovrà ricevere due argomenti interi
e restituire 1 se è vero, altrimenti falso, utilizzate questa funzione in un programma 
che prenda in input una serie di coppie di interi
**/

#include <stdio.h>
#include <stdlib.h>

int multiple(int, int);

int main(int argc, char const *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	printf("Risultato: %d", multiple(a,b));

	return 0;
}

int multiple(int a, int b){
	return (a % b == 0)? 1 : 0;
}