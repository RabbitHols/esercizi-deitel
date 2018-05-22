/*
 * Prendere un intero e dire quanti 7 vi sono dentro
 */

#include <stdio.h>

int main(){
	
	int numero 	= 1772;
	int resto;
	int numSev	= 0;

	while(numero != 0){
		resto = numero % 10;
		if(resto != 7) 
			numSev++;
		numero = numero / 10; 
	}	

	printf("Sono stati trovati %d 7", numSev);

	return 0;
}
