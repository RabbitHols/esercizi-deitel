/*
 * Trova il fattoriale di un numero
 */

#include <stdio.h>


int main(){
	
	int n = 5;
	for(int i = n - 1; i >= 1; i--){
		n = n * i;
	}
	

	printf("NUMERO : %d", n);


	return 0;
}
