/**
 * Creare un funzione che dia il valore massimo tra 3 interi
 **/

/**
 * Normalmente il libro usa la tecnica delle if e poi dell'esclusione ma dato che è noiosa e verbosa penso che usare delle
 * macro sia un tecnicna migliore per questo genere di programma
 **/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)  ( ((a) > (b) )? a : b )

// Il libro propone questa soluzione alquanto verbosa

int maximum(int, int, int);

int main(int argc, char const *argv[]){





	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);
	
	int max = MAX(MAX(a,b),c);

	printf("%d\n", max);
	printf("%d\n", maximum(a,b,c));

	return 0;
}


int maximum(int x, int y, int z){

	int max = x;

	if(y > max){
		max = y;
	} else{
		max = z;
	}


	return max;
}

