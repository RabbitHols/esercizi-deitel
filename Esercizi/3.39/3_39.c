/*
 * Prendere un intero e dire quanti 7 vi sono dentro
 */

#include <stdio.h>

int main(){
	
	int numero = 177;

	float test = (float) numero;
	int dec = 100;
	int unit;

	for(int i = 0; i < 3; i++){
		
	unit = numero / dec;
	if(unit == 7){printf("TROVATO !\n");}
	numero = numero % dec;
	dec = dec / 10;	
		
	}

	return 0;
}
