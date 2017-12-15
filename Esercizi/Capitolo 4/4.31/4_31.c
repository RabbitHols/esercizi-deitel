/*
 * Disegna un rombo con le printf di 9 righe
 */

#include <stdio.h>

int main(){

	int cont 	= 0x0;
	int spazio 	= 0x0;
	int asterischi	= 0x0;
	int i = 4;
	int j = 0;
	int tester = 0;	

	for(cont; cont <= 10; cont++){
		for(spazio = 0; spazio <= i; spazio++){
			printf(" ");
		}
		for(asterischi = 0; asterischi <= j; asterischi++){
			printf("*");
		}
		printf("\n");
		i--;
		if(cont <= 4){	j = j + 2; }
		if(cont >  4){
			
			for(spazio; spazio <= tester; spazio++){
				printf(" ");
			}

			j = j - 2;
	       		tester++;
		}	
	}


	return 0;
}
