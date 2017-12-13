/*
 * Trova la costante di Nepero
 *
 * e = 1 + 1/1! + 1/2! ecc..
 *
 */
#include <stdio.h>
#include <math.h>

float fattoriale(float nr);

int main (){

 	long double nepero = 1;

	for(double cont = 1; cont < 32; cont++){
		nepero = nepero + 1 / fattoriale(cont);
	}

	printf("\n%Lf", nepero);

return 0;
	
}

float fattoriale(float nr){
	
	if(nr == 1){return 1;}

	for(int cont = nr - 1; cont >= 1; cont-- ){
		nr = nr * cont;
	}

	return nr;
}
