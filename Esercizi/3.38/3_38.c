/*
 * Stampare 100 asterischi ogni 10 applica un \n
 */


#include <stdio.h>

int main(){

	for(int i = 1; i <= 100; i++){
		printf("*");
		if(i % 10 == 0){printf("\n");}
	}

	return 0;
}
